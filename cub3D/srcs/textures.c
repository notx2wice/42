/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-eunju <kim-eunju@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:10:14 by ekim              #+#    #+#             */
/*   Updated: 2021/01/06 21:17:15 by kim-eunju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void			load_image(t_window *window, char *path, int idx)
{
	path[(int)ft_strlen(path) - 1] = '\0';
	if (!(window->img[idx]->img = mlx_xpm_file_to_image(window->mlx,
		(char *)path, &window->img[idx]->width, &window->img[idx]->height)))
		exit_program("Path name error");
	if (!(window->img[idx]->data =
			(unsigned int *)mlx_get_data_addr(window->img[idx]->img,
			&window->img[idx]->bpp, &window->img[idx]->line_length,
			&window->img[idx]->endian)))
		exit_program("mlx_get_data_addr error");
}

void				load_texture(t_window *window)
{
	load_image(window, window->cub->no_path, NO_IDX);
	load_image(window, window->cub->so_path, SO_IDX);
	load_image(window, window->cub->we_path, WE_IDX);
	load_image(window, window->cub->ea_path, EA_IDX);
	load_image(window, window->cub->sprite_path, S_IDX);
}

void				calc_wall_texture(t_window *window, t_ray *ray)
{
	if (ray->side == 0)
	{
		ray->tex_num = (ray->ray_dir.x > 0) ? 1 : 0;
		ray->wall_x = window->player->pos.y +
			ray->perpwall_dist * ray->ray_dir.y;
	}
	else
	{
		ray->tex_num = (ray->ray_dir.y > 0) ? 3 : 2;
		ray->wall_x = window->player->pos.x +
			ray->perpwall_dist * ray->ray_dir.x;
	}
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)window->img[ray->tex_num]->width);
	if ((ray->side == 0 && ray->ray_dir.x > 0) ||
		(ray->side == 1 && ray->ray_dir.y < 0))
		ray->tex_x = window->img[ray->tex_num]->width - ray->tex_x - 1;
}

void				floor_ceiling_to_buffer(t_window *window)
{
	int				x;
	int				y;

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

void				wall_to_buffer(t_window *window, t_ray *ray, int x)
{
	double			step;
	double			tex_pos;
	int				y;
	unsigned int	color;

	step = window->img[ray->tex_num]->height * 1.0 / ray->lineheight;
	tex_pos = (ray->draw_start - window->cub->res_height / 2 +
		ray->lineheight / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)tex_pos & window->img[ray->tex_num]->height - 1;
		tex_pos += step;
		color =
			window->img[ray->tex_num]->data[window->img[ray->tex_num]->width *
			ray->tex_y + ray->tex_x];
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		window->buffer[y][x] = color;
		y++;
	}
	ray->z_buffer[x] = ray->perpwall_dist;
}
