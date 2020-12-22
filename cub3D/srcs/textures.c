/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekim <ekim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:10:14 by ekim              #+#    #+#             */
/*   Updated: 2020/12/19 23:10:14 by ekim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				*loadImage(t_window *window, char *path, t_img *img)
{
	int			*res;
	int			x;
	int			y;

	if (!(img->img = mlx_xpm_file_to_image(window->mlx, path, &img->width, &img->height)))
		exit_program("mlx_xpm_file_to_image error");
	if (!(img->data = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian)))
		exit_program("mlx_get_data_addr error");
	if (!(res = (int *)malloc(sizeof(int) * (img->width * img->height))))
		exit_program(MEMORY_ALLOC_ERROR);
	x = 0;
	y = 0;
	while (y < img->height)
	{
		while (x < img->width)
		{
			res[img->width * y + x] = img->data[img->width * y + x];
			x++;
		}
		y++;
	}
	//mlx function -> get image data and destroy it to get another img next time.
	//mlx_destroy_image(window->mlx, img->img); //추후 실행
	return (res);
}

void			load_texture(t_window *window)
{
	window->textures[NO_IDX] = loadImage(window, window->cub->no_path, window->img[0]);
	window->textures[SO_IDX] = loadImage(window, window->cub->so_path, window->img[1]);
	window->textures[WE_IDX] = loadImage(window, window->cub->we_path, window->img[2]);
	window->textures[EA_IDX] = loadImage(window, window->cub->ea_path, window->img[3]);
	window->textures[SPRITE_IDX] = loadImage(window, window->cub->sprite_path, window->img[4]);
}

void			floor_ceiling_to_buffer(t_window *window)
{
	int			y;
	int			x;

	y = 0;
	x = 0;
	while (x < window->cub->res_width)
	{
		while (y < window->cub->res_height / 2)
		{
			window->buffer[y][x] = window->cub->ceiling_color;
			y++;
		}
		y = window->cub->res_height / 2;
		while (y < window->cub->res_height)
		{
			window->buffer[y][x] = window->cub->floor_color;
			y++;
		}
		x++;
	}
}

void			wall_to_buffer(t_window *window, t_ray *ray, int x)
{
	double		step;
	double		tex_pos;
	int			y;
	int			color;

	step = window->img[ray->tex_num]->height * 1.0 / ray->lineheight;
	tex_pos = (ray->draw_start - window->cub->res_height / 2 + \
		ray->lineheight / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)tex_pos & window->img[ray->tex_num]->height - 1;
		tex_pos += step;
		color = window->textures[ray->tex_num][window->img[ray->tex_num]->height \
			* ray->tex_y + ray->tex_x];
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		window->buffer[y][x] = color;
		y++;
	}
	// ?????? whilch buffer??
	// ray->z_buffer[x] = ray->perpwallDist;
}