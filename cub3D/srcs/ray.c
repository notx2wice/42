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

void			set_ray_rayDir(double cameraX, t_ray *ray, t_player *player)
{
	// calculate ray position and direction
	ray->rayDir.x = player->dir.x + player->plane.x * cameraX;
	ray->rayDir.y = player->dir.y + player->plane.y * cameraX;

	//length of ray from current position to next x or y-side
	ray->deltaDist.x = fabs(1 / ray->rayDir.x);
	ray->deltaDist.y = fabs(1 / ray->rayDir.y);//abs -?fabs
}


void		set_ray_step_sideDist(t_ray *ray, t_coord_d *pos)
{
	if (ray->rayDir.x < 0)
	{
		ray->step.x = -1;
		ray->sideDist.x = (pos->x - ray->map.x) * (ray->deltaDist.x);
	}
	else
	{
		ray->step.x = 1;
		ray->sideDist.x = (ray->map.x + 1.0 - pos->x) * (ray->deltaDist.x);
	}
	if (ray->rayDir.y < 0)
	{
		ray->step.y = -1;
		ray->sideDist.y = (pos->y - ray->map.y) * (ray->deltaDist.y);
	}
	else
	{
		ray->step.y = 1;
		ray->sideDist.y = (ray->map.y + 1 - pos->y) * (ray->deltaDist.y);
	}
}

void			find_and_calc_wall(t_ray *ray, t_cub *cub)
{
	while (ray->hit == 0)
	{
		//jump to next map square, Or in x-direction, Or in y-direction
		if (ray->sideDist.x < ray->sideDist.y)
		{
			ray->sideDist.x += ray->deltaDist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sideDist.x += ray->deltaDist.x;
			ray->map.x += ray->step.x;
			ray->side = 1;
		}

		//check if ray has hit a wall
		if (cub->worldmap[ray->map.x][ray->map.y] == '1')
			ray->hit = 1;
	}
}

void			calc_perp_lineheight_drawS_drawE(t_ray *ray, t_player *player, t_cub *cub)
{
	//calculate distance projected on camera direction
	if (ray->side == 0)
		ray->perpwallDist = (ray->map.x - player->pos.x + \
			(1 - ray->step.x) / 2) / ray->rayDir.x;
	else
		ray->perpwallDist = (ray->map.y - player->pos.y + \
			(1 - ray->step.y) / 2) / ray->rayDir.y;

	//calculate height of line to draw on screen
	ray->lineheight = (int)((double)cub->res_height / ray->perpwallDist);

	//calculate lowest and highest pixel to fill in current stripe.
	ray->draw_start = (-1 * ray->lineheight / 2) + (cub->res_height / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->lineheight / 2) + (cub->res_height / 2);
	if (ray->draw_end >= cub->res_height)
		ray->draw_end = cub->res_height - 1;
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

void			do_raycasting(t_window *window)
{
	double		cameraX;
	int			x;

	// which box of the map we're in(initialize)
	window->ray->map.x = window->player->pos.x;
	window->ray->map.y = window->player->pos.y;

	x = 0;
	while (x < window->cub->res_width)
	{
		//calculate ray position and direction
		cameraX = 2 * x / window->cub->res_width - 1;
		set_ray_rayDir(cameraX, window->ray, window->player);

		//calculate step and initial sideDist
		set_ray_step_sideDist(window->ray, &window->player->pos);

		//check whether the ray hit the wall or not.
		find_and_calc_wall(window->ray, window->cub);

		//calculate get perpwallDist, lineheight, drawStart, drawEnd.
		calc_perp_lineheight_drawS_drawE(window->ray, &window->player, window->cub);//&cub

		//define tex_num & tex_x & wall_x
		calc_wall_texture(window, window->ray);

		//transform each pixel's color to array.
		wall_to_buffer(window, window->ray, x);
		x++;
	}
}

int			raycasting(t_window *window)
{
	set_player_dir_plane_coord(window);

	//draw wall and ceiling
	floor_ceiling_to_buffer(window);

	do_raycasting(window);
	return (0);
}