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

void			loadImage(t_window *window, char *path, int idx)
{
	int			*res;
	int			x;
	int			y;

	path[(int)ft_strlen(path) - 1] = '\0';
	if (!(window->img[idx]->img = mlx_xpm_file_to_image(window->mlx, (char *)path, \
			&window->img[idx]->width, &window->img[idx]->height)))
			exit_program("mlx_xpm_file_to_image error");
	if (!(window->img[idx]->data = mlx_get_data_addr(window->img[idx]->img, \
			&window->img[idx]->bpp, &window->img[idx]->line_length, \
			&window->img[idx]->endian)))
		exit_program("mlx_get_data_addr error");
	if (!(res = (int *)malloc(sizeof(int) * (window->cub->res_width \
			* window->cub->res_height))))
		exit_program(MEMORY_ALLOC_ERROR);
	x = -1;
	y = -1;
	while (++y < window->img[idx]->height)
		while (++x < window->img[idx]->width)
			res[window->img[idx]->width * y + x] \
				= window->img[idx]->data[window->img[idx]->width * y + x];
	window->textures[idx] = res;
	// mlx_destroy_image(window->mlx, window->img[idx]->img); //추후 실행
}

void			load_texture(t_window *window)
{
	loadImage(window, window->cub->no_path, NO_IDX);
	loadImage(window, window->cub->so_path, SO_IDX);
	loadImage(window, window->cub->we_path, WE_IDX);
	loadImage(window, window->cub->ea_path, EA_IDX);
	loadImage(window, window->cub->sprite_path, SPRITE_IDX);
}

void			calc_wall_texture(t_window *window, t_ray *ray)
{
	if (ray->side == 0)
	{
		ray->tex_num = (ray->rayDir.x > 0)? 1: 0; //0북 1남 2서 3동
		ray->wall_x = window->player->pos.x + ray->perpwallDist * ray->rayDir.y;
	}
	else
	{
		ray->tex_num = (ray->rayDir.y > 0)? 3 : 2;
		ray->wall_x = window->player->pos.y + ray->perpwallDist * ray->rayDir.x;
	}
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * window->img[ray->tex_num]->width);
	if ((ray->side == 0 && ray->rayDir.x > 0) || (ray->side == 1 && ray->rayDir.y < 0))
		ray->tex_x = window->img[ray->tex_num]->width - ray->tex_x - 1;
}

void			set_texture(t_window *window, int x)
{
	t_line		*line;

	if (!(line = malloc(sizeof(t_line))))
		exit_program(MEMORY_ALLOC_ERROR);
	ft_bzero(line, sizeof(t_line));
	line->x = x;
	calc_wall_texture(window, window->ray);
	// wall_to_buffer(window, window->ray, x);

	if (window->cub->worldmap[window->ray->map.y][window->ray->map.x] == '1')
	{
		line->y0 = window->ray->draw_end;
		line->y1 = window->ray->draw_start;
		line->tex_x = window->ray->tex_x;
		ver_line_texture_image(line, window, window->img[window->ray->tex_num], window->ray);
	}
	line->y0 = 0;
	line->y1 = window->ray->draw_start;
	ver_line_color_image(line, window, window->cub->ceiling_color);
	line->y0 = window->cub->res_height;
	line->y1 = window->ray->draw_end;
	ver_line_color_image(line, window, window->cub->floor_color);
}

void			floor_ceiling_to_buffer(t_window *window)
{
	int			y;
	int			x;

	x = 0;
	while (x < window->cub->res_width)
	{
		y = 0;
		while (y < window->cub->res_height / 2)
		{
			window->buffer[y][x] = window->cub->ceiling_color;
			y++;
		}
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
	tex_pos = (ray->draw_start - window->cub->res_height / 2 + ray->lineheight / 2) * step;
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
	ray->z_buffer[x] = ray->perpwallDist;
}