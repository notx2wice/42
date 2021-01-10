/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-eunju <kim-eunju@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 20:23:22 by ekim              #+#    #+#             */
/*   Updated: 2021/01/10 18:44:02 by kim-eunju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void			set_sprites_coord_distance(t_window *window, int s_cnt)
{
	int				idx;

	idx = 0;
	while (idx < s_cnt)
	{
		window->sprites[idx]->distance =
			sqrt(pow(window->player->pos.x -
			(double)window->sprites[idx]->x, 2) +
			pow(window->player->pos.y - (double)window->sprites[idx]->y, 2));
		idx++;
	}
}

static void			sort_sprites(t_window *window, int s_cnt)
{
	int				i;
	int				j;
	t_sprite		*sprite;

	i = -1;
	while (++i < s_cnt)
	{
		j = i;
		while (++j < s_cnt)
			if (window->sprites[i]->distance < window->sprites[j]->distance)
			{
				sprite = window->sprites[j];
				window->sprites[j] = window->sprites[i];
				window->sprites[i] = sprite;
			}
	}
}

static void			pick_sprites_texture_color
(
	t_window *window,
	t_d_sprites *sprites,
	int stripe
)
{
	int				y;
	int				d;
	int				tex_y;
	int				color;

	if (sprites->transform_y > 0 && stripe > 0
		&& stripe < window->cub->res_width
		&& sprites->transform_y < window->ray->z_buffer[stripe])
	{
		y = sprites->draw_start_y;
		while (y < sprites->draw_end_y)
		{
			d = y * 256 - window->cub->res_height * 128 +
				sprites->sprite_height * 128;
			tex_y = (int)(((double)(d * window->img[S_IDX]->height) /
				(double)sprites->sprite_height) / 256.0);
			color = window->img[S_IDX]->data[window->img[S_IDX]->width *
				tex_y + sprites->tex_x];
			if ((color & 0x00FFFFFF) != 0)
				window->buffer[y][stripe] = color;
			y++;
		}
	}
}

void				sprite_raycast(t_window *window, t_d_sprites *sprites)
{
	int				i;
	int				stripe;

	i = 0;
	while (i < window->cub->sprite_cnt)
	{
		calc_transform_x_y(window, window->player, window->d_sprites, i);
		calc_screenx_height_draw(window, window->d_sprites,
			(double)window->cub->res_width,
			(double)window->cub->res_height);
		stripe = window->d_sprites->draw_start_x;
		while (stripe < window->d_sprites->draw_end_x)
		{
			window->d_sprites->tex_x =
				(int)((256.0 * ((double)stripe -
				((double)(-sprites->sprite_width) / 2.0 +
				(double)sprites->screen_x)) * (double)window->img[S_IDX]->width
				/ (double)sprites->sprite_width) / 256.0);
			pick_sprites_texture_color(window, window->d_sprites, stripe);
			stripe++;
		}
		i++;
	}
}

void				draw_sprite(t_window *window)
{
	int				s_cnt;

	s_cnt = window->cub->sprite_cnt;
	set_sprites_coord_distance(window, s_cnt);
	sort_sprites(window, s_cnt);
	sprite_raycast(window, window->d_sprites);
}
