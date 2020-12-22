/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekim <ekim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:28:51 by ekim              #+#    #+#             */
/*   Updated: 2020/12/15 19:28:51 by ekim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			init_coord_d(t_coord_d coord_d)
{
	coord_d.x = 0;
	coord_d.y = 0;
}

void			init_coord_i(t_coord_i coord_i)
{
	coord_i.x = 0;
	coord_i.y = 0;
}

void			init_player(t_player *player)
{
	if (!(player = malloc(sizeof(t_player))))
		exit_program(MEMORY_ALLOC_ERROR);
	init_coord_d(player->pos);
	init_coord_d(player->dir);
	init_coord_d(player->plane);
}

void			init_sprite(t_sprite *sprite)
{
	if (!(sprite = malloc(sizeof(t_sprite))))
		exit_program(MEMORY_ALLOC_ERROR);
	sprite.x = 0;
	sprite.y = 0;
	sprite.distance = 0;
}

void			init_tex(t_tex *tex)
{
	tex.x = 0;
	tex.y = 0;
	tex.texNum = 0;
}

void			init_cub(t_cub *cub)
{
	if (!(cub = malloc(sizeof(t_cub))))
		exit_program(MEMORY_ALLOC_ERROR);
	cub->no_path = "";
	cub->so_path = "";
	cub->ea_path = "";
	cub->we_path = "";
	cub->sprite_path = "";
	cub->floor_color = 0;
	cub->ceiling_color = 0;
	cub->map_col = 0;
	cub->map_row = 0;
	cub->res_width = 0;
	cub->res_height = 0;
	cub->sprite_cnt = 0;
}

void        init_ray(t_ray *ray)
{
	if (!(ray = malloc(sizeof(t_ray))))
		exit_program(MEMORY_ALLOC_ERROR);
	ray->cameraX = 0;
	init_coord_i(ray->map);
	init_coord_i(ray->step);
	init_coord_d(ray->rayDir);
	init_coord_d(ray->sideDist);
	init_coord_d(ray->deltaDist);
	ray->perpwallDist = 0;
    ray->hit = 0;
    ray->side = 0;
	ray->lineheight = 0;
    ray->draw_start = 0;
    ray->draw_end = 0;
	ray->buffer = 0;
}

void		init_img(t_img *img)
{
	if (!(img = malloc(sizeof(t_img))))
		exit_program(MEMORY_ALLOC_ERROR);
	img->img = "";
	img->addr = "";
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
}

void		init_key(t_key *key)
{
	if (!(key = malloc(sizeof(t_key))))
		exit_program(MEMORY_ALLOC_ERROR);
	key->go = 0;
	key->back = 0;
	key->left = 0;
	key->right = 0;
	key->turn = 0;
	key->rotate_left = 0;
	key->rotate_right = 0;
}

void		init_window(t_window *window)
{
	if (!(window = malloc(sizeof(t_window))))
		exit_program(MEMORY_ALLOC_ERROR);
	window->mlx = "";
	window->win_mlx = "";
	window->rotate_speed = 0.05;
	window->move_speed = 0.05;
	init_img(window->img);
// init_textures?
	init_ray(window->ray);
	init_player(window->player);
	init_key(window->key);
	init_cub(window->cub);
	init_sprite(window->sprite);
	

}