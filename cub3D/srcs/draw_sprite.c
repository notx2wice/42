/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekim <ekim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 20:23:22 by ekim              #+#    #+#             */
/*   Updated: 2020/12/19 20:23:22 by ekim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void			set_sprites_coord_distance(t_window *window, int s_cnt)
{
	int				idx;

	idx = 0;
	while (idx < s_cnt)
	{
		window->sprites[idx]->distance \
		= sqrt(pow(window->player->pos.x \
		- (double)window->sprites[idx]->x , 2) \
		+ pow(window->player->pos.y - (double)window->sprites[idx]->y , 2));
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

static void			calc_transform_X_Y
(
	t_window *window,
	t_player *player,
	t_d_sprites *sprites,
	int idx)
{
	double			spriteX;
	double			spriteY;
	double			invDet;

	spriteX = window->sprites[idx]->x - window->player->pos.x;
	spriteY = window->sprites[idx]->y - window->player->pos.y;
	invDet = 1.0 / (player->plane.x * player->dir.y - player->dir.x \
					* player->plane.y);
	sprites->transformX = invDet * (player->dir.y * spriteX \
									- player->dir.x * spriteY);
	sprites->transformY = invDet * (-player->plane.y * spriteX \
									+ player->plane.x * spriteY);
	sprites->screenX 
		= (int)(((double)window->cub->res_width / 2.0) \
			* (1.0 + window->d_sprites->transformX / sprites->transformY));
	sprites->spriteHeight = abs((int)(window->cub->res_height \
								/ sprites->transformY)); 
}

static void			calc_ScreenX_Height_draw
(
	t_window *window, 
	t_d_sprites *sprites, 
	double s_width, 
	double s_height
)
{
	sprites->drawStart_y = (int)((double)(-sprites->spriteHeight) \
							/ 2.0 + window->cub->res_height / 2.0);
	if (sprites->drawStart_y < 0)
		sprites->drawStart_y = 0;
	sprites->drawEnd_y = (int)((double)sprites->spriteHeight / 2.0 \
							+ s_height / 2.0);
	if (sprites->drawEnd_y >= (int)s_height)
		sprites->drawEnd_y = s_height - 1;
	sprites->spriteWidth = abs((int)(s_height / sprites->transformY));
	sprites->drawStart_x = (int)((double)(-sprites->spriteWidth) / 2.0 \
							+ (double)sprites->screenX);
	if (sprites->drawStart_x < 0)
		sprites->drawStart_x = 0;
	sprites->drawEnd_x = (int)((double)sprites->spriteWidth / 2.0 \
							+ (double)sprites->screenX);
	if (sprites->drawEnd_x >= (int)s_width)
		sprites->drawEnd_x = (int)s_width - 1;
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
	int				texY;
	int				color;

	if (sprites->transformY > 0 && stripe > 0 
		&& stripe < window->cub->res_width \
		&& sprites->transformY < window->ray->z_buffer[stripe])
	{
		y = sprites->drawStart_y;
		while (y < sprites->drawEnd_y)
		{
			d = y * 256 - window->cub->res_height * 128 + \
				sprites->spriteHeight * 128;
			texY = (int)(((double)(d * window->img[S_IDX]->height) \
					/ (double)sprites->spriteHeight) / 256.0);
			color = window->img[S_IDX]->data[window->img[S_IDX]->width\
					* texY + sprites->tex_x];
			if ((color & 0x00FFFFFF) != 0)
				window->buffer[y][stripe] = color;
			y++;
		}
	}
}

static void			sprite_raycast(t_window *window, t_d_sprites *sprites)
{
	int				i;
	int				stripe;

	i = 0;
	while (i < window->cub->sprite_cnt)
	{
		calc_transform_X_Y(window, window->player, window->d_sprites, i);
		calc_ScreenX_Height_draw(window, window->d_sprites, \
								(double)window->cub->res_width, \
								(double)window->cub->res_height);
		//loop through every vertical stripe of the sprite on screen
		stripe = window->d_sprites->drawStart_x;
		while (stripe < window->d_sprites->drawEnd_x)
		{
			window->d_sprites->tex_x 
				= (int)((256.0 * ((double)stripe - \
				((double)(-sprites->spriteWidth) \
				/ 2.0 + (double)sprites->screenX)) * \
				(double)window->img[S_IDX]->width / \
				(double)sprites->spriteWidth)  / 256.0);
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