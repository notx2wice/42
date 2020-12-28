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
	printf("rayDir.x : %f\n", ray->rayDir.x);
	printf("rayDir.y : %f\n", ray->rayDir.y);

	//length of ray from current position to next x or y-side
	ray->deltaDist.x = fabs(1 / ray->rayDir.x);
	ray->deltaDist.y = fabs(1 / ray->rayDir.y);
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
			ray->sideDist.y += ray->deltaDist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		//check if ray has hit a wall
		if (cub->worldmap[ray->map.x][ray->map.y] == '1')
			ray->hit = 1;
	}
	ray->hit = 0;
}

void			calc_perp_lineheight_drawS_drawE(t_ray *ray, t_player *player, t_cub *cub)
{
	//calculate distance projected on camera direction
	printf("pos.x : %f\n", player->pos.x);
	printf("pos.y : %f\n", player->pos.y);
	if (ray->side == 0)
		ray->perpwallDist = ((double)ray->map.x - player->pos.x + \
			(double)(1 - ray->step.x) / 2.0) / ray->rayDir.x;
	else
		ray->perpwallDist = ((double)ray->map.y - player->pos.y + \
			(double)(1 - ray->step.y) / 2.0) / ray->rayDir.y;
	printf("perpwalldist : %f\n", ray->perpwallDist);
	
	//calculate height of line to draw on screen
	ray->lineheight = (int)((double)cub->res_height / ray->perpwallDist);
	printf("lineheight : %d\n", ray->lineheight);

	//calculate lowest and highest pixel to fill in current stripe.
	ray->draw_start = (-ray->lineheight / 2.0) + (cub->res_height / 2.0);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->lineheight / 2) + (cub->res_height / 2);
	if (ray->draw_end >= cub->res_height)
		ray->draw_end = cub->res_height - 1;
	printf("draw_start : %d\n", ray->draw_start);
	printf("draw_end : %d\n", ray->draw_end);
}

void			do_raycasting(t_window *window)
{
	double		cameraX;
	int			x;

	x = 0;
	while (x < window->cub->res_width)
	{
		// which box of the map we're in(initialize)
		window->ray->map.x = (int)window->player->pos.x;
		window->ray->map.y = (int)window->player->pos.y;

		//calculate ray position and direction
		cameraX = 2 * (double)x / window->cub->res_width - 1;
		set_ray_rayDir(cameraX, window->ray, window->player);

		//calculate step and initial sideDist
		set_ray_step_sideDist(window->ray, &window->player->pos);

		//check whether the ray hit the wall or not.
		find_and_calc_wall(window->ray, window->cub);

		//calculate get perpwallDist, lineheight, drawStart, drawEnd.
		calc_perp_lineheight_drawS_drawE(window->ray, window->player, window->cub);//&cub

		set_texture(window, x);
		x++;
	}
}

int			raycasting(t_window *window)
{
	if (!(window->ray->z_buffer = (double *)malloc(sizeof(double) * window->cub->res_width)))
		exit_program(MEMORY_ALLOC_ERROR);
	ft_bzero(window->ray->z_buffer, sizeof(double) * window->cub->res_width);
	
	//basic setting
	set_player_dir_plane_coord(window);

	//draw wall and ceiling
	floor_ceiling_to_buffer(window);

	do_raycasting(window);

	mlx_put_image_to_window(window->mlx, window->win, window->pimg->img, 0, 0);
	return (0);
}