/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekim <ekim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:45:57 by ekim              #+#    #+#             */
/*   Updated: 2020/12/14 21:45:57 by ekim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			set_player_dir_plane_coord(t_window *window)
{
	if (window->cub->p_direction == 'W')
	{
		window->player->dir.y = 1;
		window->player->plane.x = 0.66;
	}
	else if (window->cub->p_direction == 'E')
	{
		window->player->dir.y = -1;
		window->player->plane.x = -0.66;
	}
	else if (window->cub->p_direction == 'S')
	{
		window->player->dir.x = -1;
		window->player->plane.y = 0.66;
	}
	else if (window->cub->p_direction == 'N')
	{
		window->player->dir.x = 1;
		window->player->plane.y = -0.66;
	}
}

void			set_ray_rayDir(double cameraX, t_ray *ray, t_player *player)
{
	ray->rayDir.x = player->dir.x + player->plane.x * cameraX;
	ray->rayDir.y = player->dir.y + player->plane.y * cameraX;
	ray->deltaDist.x = sqrt(1 + (ray->rayDir.y * ray->rayDir.y) \
						/ (ray->rayDir.x * ray->rayDir.x));
	ray->deltaDist.y = sqrt(1 + (ray->rayDir.x * ray->rayDir.x) \
						/ (ray->rayDir.y * ray->rayDir.y));
}


void		set_ray_step_sideDist(t_ray *ray, t_coord_d *pos)
{
	if (ray->rayDir.x < 0)
	{
		ray->step.x = -1;
		ray->sideDist.x = (pos->x - (double)ray->map.x) * (ray->deltaDist.x);
	}
	else
	{
		ray->step.x = 1;
		ray->sideDist.x = ((double)ray->map.x + 1.0 - pos->x) \
							* (ray->deltaDist.x);
	}
	if (ray->rayDir.y < 0)
	{
		ray->step.y = -1;
		ray->sideDist.y = (pos->y - (double)ray->map.y) * (ray->deltaDist.y);
	}
	else
	{
		ray->step.y = 1;
		ray->sideDist.y = ((double)ray->map.y + 1.0 - pos->y) \
							* (ray->deltaDist.y);
	}
}

void			find_and_calc_wall(t_ray *ray, t_cub *cub)
{
	while (ray->hit == 0)
	{
		if (ray->sideDist.x < ray->sideDist.y)
		{
			ray->sideDist.x += ray->deltaDist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sideDist.y += ray->deltaDist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (cub->worldmap[ray->map.x][ray->map.y] == '1')
			ray->hit = 1;
	}
	ray->hit = 0;
}

void			calc_perp_lineheight_drawS_drawE
(
	t_ray *ray,
	t_player *player,
	t_cub *cub
)
{
	if (ray->side == 0)
		ray->perpwallDist = ((double)ray->map.x - player->pos.x + \
			(double)(1 - ray->step.x) / 2.0) / ray->rayDir.x;
	else
		ray->perpwallDist = ((double)ray->map.y - player->pos.y + \
			(double)(1 - ray->step.y) / 2.0) / ray->rayDir.y;
	ray->lineheight = (int)((double)cub->res_height / ray->perpwallDist);
	ray->draw_start = (int)(((-1.0) * (double)ray->lineheight / 2.0) + \
						((double)cub->res_height / 2.0));
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (int)(((double)ray->lineheight / 2.0) + \
					((double)cub->res_height / 2.0));
	if (ray->draw_end >= cub->res_height)
		ray->draw_end = cub->res_height - 1;
}