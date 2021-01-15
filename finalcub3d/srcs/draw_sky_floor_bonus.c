/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky_floor_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:06:02 by ukim              #+#    #+#             */
/*   Updated: 2021/01/14 20:31:52 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_ray_step(int y, t_ray *ray, t_cub *cub, t_player *player)
{
	double floor_step_x;
	double floor_step_y;
	double floor_step_x_ray;
	double floor_step_y_ray;

	ray->p = y - cub->res_height / 2;
	ray->pos_z = 0.5 * cub->res_height;
	ray->row_dist = ray->pos_z / ray->p;
	floor_step_x_ray = ray->ray_dir1.x - ray->ray_dir0.x;
	floor_step_y_ray = ray->ray_dir1.y - ray->ray_dir0.y;
	floor_step_x = ray->row_dist * floor_step_x_ray / cub->res_width;
	floor_step_y = ray->row_dist * floor_step_y_ray / cub->res_width;
	ray->floor_step.x = floor_step_x;
	ray->floor_step.y = floor_step_y;
	ray->floor.x = player->pos.x + ray->row_dist * ray->ray_dir0.x;
	ray->floor.y = player->pos.y + ray->row_dist * ray->ray_dir0.y;
}

static int	calc_tex_x(t_window *window, int texture)
{
	int		width;
	double	floor_x;
	double	cell_x;

	width = window->img[texture]->width;
	floor_x = window->ray->floor.x;
	cell_x = window->ray->cell.x;
	return ((int)(width * (floor_x - cell_x)) & (width - 1));
}

static int	calc_tex_y(t_window *window, int texture)
{
	int		height;
	double	floor_y;
	double	cell_y;

	height = window->img[texture]->height;
	floor_y = window->ray->floor.y;
	cell_y = window->ray->cell.y;
	return ((int)(height * (floor_y - cell_y)) & (height - 1));
}

static void	set_buffer(t_window *window, int x, int y, int tex_num)
{
	unsigned int	color;
	int				tex_width;
	int				tex_height;
	int				tex_x;
	int				tex_y;

	tex_x = calc_tex_x(window, tex_num);
	tex_y = calc_tex_y(window, tex_num);
	tex_width = window->img[tex_num]->width;
	tex_height = window->img[tex_num]->height;
	color = (unsigned int)window->img[tex_num]->data[tex_width * tex_y + tex_x];
	color = (color >> 1) & 8355711;
	if (tex_num == FT_IDX)
	{
		y = window->cub->res_height - y - 1;
		window->buffer[y][x] = color;
	}
	else
	{
		window->buffer[y][x] = color;
	}
}

void		draw_sky_floor(t_window *window)
{
	int				x;
	int				y;
	t_ray			*ray;

	ray = window->ray;
	ray->ray_dir0.x = (window->player->dir.x) - (window->player->plane.x);
	ray->ray_dir0.y = (window->player->dir.y) - (window->player->plane.y);
	ray->ray_dir1.x = (window->player->dir.x) + (window->player->plane.x);
	ray->ray_dir1.y = (window->player->dir.y) + (window->player->plane.y);
	y = 0;
	while (y < window->cub->res_height)
	{
		set_ray_step(y, ray, window->cub, window->player);
		x = 0;
		while (++x < window->cub->res_width)
		{
			ray->cell.x = (int)(ray->floor.x);
			ray->cell.y = (int)(ray->floor.y);
			set_buffer(window, x, y, ST_IDX);
			set_buffer(window, x, y, FT_IDX);
			ray->floor.x += ray->floor_step.x;
			ray->floor.y += ray->floor_step.y;
		}
		y++;
	}
}
