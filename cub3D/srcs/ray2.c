/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-eunju <kim-eunju@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 19:53:08 by kim-eunju         #+#    #+#             */
/*   Updated: 2021/01/02 22:47:34 by kim-eunju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		do_raycasting(t_window *window)
{
	double		cameraX;
	int			x;

	x = 0;
	while (x < window->cub->res_width)
	{
		window->ray->map.x = (int)window->player->pos.x;
		window->ray->map.y = (int)window->player->pos.y;
		cameraX = 2.0 * (double)x / (double)window->cub->res_width - 1.0;
		set_ray_rayDir(cameraX, window->ray, window->player);
		set_ray_step_sideDist(window->ray, &window->player->pos);
		find_and_calc_wall(window->ray, window->cub);
		calc_perp_lineheight_drawS_drawE(window->ray, window->player, \
                                            window->cub);
		calc_wall_texture(window, window->ray);
		wall_to_buffer(window, window->ray, x);
		x++;
	}
}

int			raycasting(t_window *window)
{
	// draw wall and ceiling
	floor_ceiling_to_buffer(window);
	do_raycasting(window);
	draw_sprite(window);
	return (SUCCESS);
}