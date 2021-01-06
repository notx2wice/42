/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-eunju <kim-eunju@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:37:21 by kim-eunju         #+#    #+#             */
/*   Updated: 2021/01/06 20:05:10 by kim-eunju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			set_player_dir_plane_coord(t_window *window)
{
	if (window->cub->p_direction == 'W')
	{
		window->player->dir.y = -1;
		window->player->plane.x = -0.66;
	}
	else if (window->cub->p_direction == 'E')
	{
		window->player->dir.y = 1;
		window->player->plane.x = 0.66;
	}
	else if (window->cub->p_direction == 'S')
	{
		window->player->dir.x = 1;
		window->player->plane.y = -0.66;
	}
	else if (window->cub->p_direction == 'N')
	{
		window->player->dir.x = -1;
		window->player->plane.y = 0.66;
	}
}

void			set_ray_raydir(double camera_x, t_ray *ray, t_player *player)
{
	ray->ray_dir.x = player->dir.x + player->plane.x * camera_x;
	ray->ray_dir.y = player->dir.y + player->plane.y * camera_x;
	ray->delta_dist.x = sqrt(1 + (ray->ray_dir.y * ray->ray_dir.y)
						/ (ray->ray_dir.x * ray->ray_dir.x));
	ray->delta_dist.y = sqrt(1 + (ray->ray_dir.x * ray->ray_dir.x)
						/ (ray->ray_dir.y * ray->ray_dir.y));
}

void			set_ray_step_sidedist(t_ray *ray, t_coord_d *pos)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (pos->x - (double)ray->map.x) * (ray->delta_dist.x);
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = ((double)ray->map.x + 1.0 - pos->x)
							* (ray->delta_dist.x);
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (pos->y - (double)ray->map.y) * (ray->delta_dist.y);
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = ((double)ray->map.y + 1.0 - pos->y)
							* (ray->delta_dist.y);
	}
}

void			find_and_calc_wall(t_ray *ray, t_cub *cub)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (cub->worldmap[ray->map.x][ray->map.y] == '1')
			ray->hit = 1;
	}
	ray->hit = 0;
}

void			calc_perp_lineheight_draws_drawe
(
	t_ray *ray,
	t_player *player,
	t_cub *cub
)
{
	if (ray->side == 0)
		ray->perpwall_dist = ((double)ray->map.x - player->pos.x +
			(double)(1 - ray->step.x) / 2.0) / ray->ray_dir.x;
	else
		ray->perpwall_dist = ((double)ray->map.y - player->pos.y +
			(double)(1 - ray->step.y) / 2.0) / ray->ray_dir.y;
	ray->lineheight = (int)((double)cub->res_height / ray->perpwall_dist);
	ray->draw_start = (int)(((-1.0) * (double)ray->lineheight / 2.0) +
						((double)cub->res_height / 2.0));
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (int)(((double)ray->lineheight / 2.0) +
					((double)cub->res_height / 2.0));
	if (ray->draw_end >= cub->res_height)
		ray->draw_end = cub->res_height - 1;
}
