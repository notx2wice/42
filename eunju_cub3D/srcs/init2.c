/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-eunju <kim-eunju@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 19:42:21 by kim-eunju         #+#    #+#             */
/*   Updated: 2021/01/05 00:53:42 by kim-eunju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			init_coord_d(t_coord_d coord_d)
{
	coord_d.x = 0;
	coord_d.y = 0;
}

void			init_player(t_player *player)
{
	init_coord_d(player->pos);
	init_coord_d(player->dir);
	init_coord_d(player->plane);
	player->cam_height = 1.0;
}

void			init_key(t_key *key)
{
	key->forward = 0;
	key->backward = 0;
	key->left = 0;
	key->right = 0;
	key->turn_left = 0;
	key->turn_right = 0;
}

void			init_cub(t_cub *cub)
{
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

void			init_ray(t_ray *ray)
{
	ray->map.x = 0;
	ray->map.y = 0;
	ray->step.x = 0;
	ray->step.y = 0;
	init_coord_d(ray->rayDir);
	init_coord_d(ray->sideDist);
	init_coord_d(ray->deltaDist);
	ray->perpwallDist = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->lineheight = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->tex_num = 0;
	ray->tex_x = 0;
	ray->tex_y = 0;
	ray->wall_x = 0;
}