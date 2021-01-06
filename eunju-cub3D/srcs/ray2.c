/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-eunju <kim-eunju@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 19:53:08 by ekim              #+#    #+#             */
/*   Updated: 2021/01/06 21:31:19 by kim-eunju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			calc_transform_x_y
(
	t_window *window,
	t_player *player,
	t_d_sprites *sprites,
	int idx
)
{
	double			sprite_x;
	double			sprite_y;
	double			inv_det;

	sprite_x = window->sprites[idx]->x - window->player->pos.x;
	sprite_y = window->sprites[idx]->y - window->player->pos.y;
	inv_det = 1.0 / (player->plane.x * player->dir.y - player->dir.x
					* player->plane.y);
	sprites->transform_x = inv_det * (player->dir.y * sprite_x -
		player->dir.x * sprite_y);
	sprites->transform_y = inv_det * (-player->plane.y * sprite_x +
		player->plane.x * sprite_y);
	sprites->screen_x =
		(int)(((double)window->cub->res_width / 2.0) *
		(1.0 + window->d_sprites->transform_x / sprites->transform_y));
	sprites->sprite_height = abs((int)(window->cub->res_height /
		sprites->transform_y));
}

void			calc_screenx_height_draw
(
	t_window *window,
	t_d_sprites *sprites,
	double s_width,
	double s_height
)
{
	sprites->draw_start_x = (int)((double)(-sprites->sprite_height) /
		2.0 + window->cub->res_height / 2.0);
	if (sprites->draw_start_y < 0)
		sprites->draw_start_y = 0;
	sprites->draw_end_y = (int)((double)sprites->sprite_height / 2.0
							+ s_height / 2.0);
	if (sprites->draw_end_y >= (int)s_height)
		sprites->draw_end_y = s_height - 1;
	sprites->sprite_width = abs((int)(s_height / sprites->transform_y));
	sprites->draw_start_x = (int)((double)(-sprites->sprite_width) / 2.0
							+ (double)sprites->screen_x);
	if (sprites->draw_start_x < 0)
		sprites->draw_start_x = 0;
	sprites->draw_end_x = (int)((double)sprites->sprite_width / 2.0
							+ (double)sprites->screen_x);
	if (sprites->draw_end_x >= (int)s_width)
		sprites->draw_end_x = (int)s_width - 1;
}

void		do_raycasting(t_window *window)
{
	double		camera_x;
	int			x;

	x = 0;
	while (x < window->cub->res_width)
	{
		window->ray->map.x = (int)window->player->pos.x;
		window->ray->map.y = (int)window->player->pos.y;
		camera_x = 2.0 * (double)x / (double)window->cub->res_width - 1.0;
		set_ray_raydir(camera_x, window->ray, window->player);
		set_ray_step_sidedist(window->ray, &window->player->pos);
		find_and_calc_wall(window->ray, window->cub);
		calc_perp_lineheight_draws_drawe(window->ray,
			window->player, window->cub);
		calc_wall_texture(window, window->ray);
		wall_to_buffer(window, window->ray, x);
		x++;
	}
}

int				raycasting(t_window *window)
{
	floor_ceiling_to_buffer(window);
	do_raycasting(window);
	draw_sprite(window);
	return (SUCCESS);
}
