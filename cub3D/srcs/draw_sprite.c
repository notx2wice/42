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

void			set_stripes_coord_distance(t_window *window, t_sprites **sprites)
{
	int			x;
	int			y;
	int			idx;
	t_sprites	s_unit;

	y = 0;
	idx = 0;
	while (window->cub->worldmap[y])
	{
		x = 0;
		while (window->cub->worldmap[y][x])
			if (window->cub->worldmap[y][x] == '2')
			{
				s_unit = malloc(sizeof(t_sprites));
				s_unit.x = x;
				s_unit.y = y;
				s_unit.distance = sqrt(pow(window->player->pos.x - x, 2) + \
					pow(window->player->pos.y - y, 2));
				*sprites[idx] = s_unit;
				idx++;
			}
			y++;
		x++;
	}
	*sprites[idx] = NULL;
}

// void			stripe_raycast(t_window *window, t_ray *ray, int x)
// {
// 	int			stripe;
// 	int			y;

// 	stripe = x;
// 	y = 
// 	while (x < ray->res_width)
// 	{
// 		while (y)
// 	}

}

void			draw_stripe(t_window *window)
{
	int			cnt;
	t_sprites	*stripes;

	idx = 0;
	cnt = window->cub->sprite_cnt;
	if (!(sprites = (t_sprites *)malloc(sizeof(t_sprites) * (cnt + 1))))
		exit_program(MEMORY_ALLOC_ERROR);
	set_sprites_coord_distance(window, &sprites);
	window->sprites = sprites;
}