/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seapark <seapark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 20:27:15 by ekim              #+#    #+#             */
/*   Updated: 2021/01/08 22:13:09 by seapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			rotate_player(t_player *player, double rot_speed, int keycode)
{
	double olddirx;
	double oldplanex;
	if (keycode == KEY_LEFT)
	{
		olddirx = player->dir.x;
		player->dir.x = player->dir.x * cos(rot_speed)
			- (player->dir.y * sin(rot_speed));
		player->dir.y = (olddirx * sin(rot_speed))
			+ (player->dir.y * cos(rot_speed));
		oldplanex = player->plane.x;
		player->plane.x = (player->plane.x * cos(rot_speed))
			- (player->plane.y * sin(rot_speed));
		player->plane.y = (oldplanex * sin(rot_speed))
			+ (player->plane.y * cos(rot_speed));
	}
	else if (keycode == KEY_RIGHT)
	{
		olddirx = player->dir.x;
		player->dir.x = player->dir.x * cos(-rot_speed)
			- (player->dir.y * sin(-rot_speed));
		player->dir.y = (olddirx * sin(-rot_speed))
			+ (player->dir.y * cos(-rot_speed));
		oldplanex = player->plane.x;
		player->plane.x = (player->plane.x * cos(-rot_speed))
			- (player->plane.y * sin(-rot_speed));
		player->plane.y = (oldplanex * sin(-rot_speed))
			+ (player->plane.y * cos(-rot_speed));
	}
}

void			move_player_forward
(
	t_player *player,
	t_cub *cub,
	double move_speed
)
{
	double		new_pos_x;
	double		new_pos_y;

	new_pos_x = (player->pos.x + player->dir.x * move_speed);
	new_pos_y = (player->pos.y + player->dir.y * move_speed);
	if (cub->worldmap[(int)new_pos_x][(int)(player->pos.y)] == '0')
		player->pos.x = new_pos_x;
	if (cub->worldmap[(int)(player->pos.x)][(int)new_pos_y] == '0')
		player->pos.y = new_pos_y;
}

void			move_player_backward
(
	t_player *player,
	t_cub *cub,
	double move_speed
)
{
	double		new_pos_x;
	double		new_pos_y;

	new_pos_x = (player->pos.x - player->dir.x * move_speed);
	new_pos_y = (player->pos.y - player->dir.y * move_speed);
	if (cub->worldmap[(int)new_pos_x][(int)(player->pos.y)] == '0')
		player->pos.x = new_pos_x;
	if (cub->worldmap[(int)(player->pos.x)][(int)new_pos_y] == '0')
		player->pos.y = new_pos_y;
}

void			move_player_right
(
	t_player *player,
	t_cub *cub,
	double move_speed
)
{
	double		new_pos_x;
	double		new_pos_y;

	new_pos_x = (player->pos.x + player->dir.y * move_speed);
	new_pos_y = (player->pos.y - player->dir.x * move_speed);
	if (cub->worldmap[(int)new_pos_x][(int)(player->pos.y)] == '0')
		player->pos.x = new_pos_x;
	if (cub->worldmap[(int)(player->pos.x)][(int)new_pos_y] == '0')
		player->pos.y = new_pos_y;
}

void			move_player_left
(
	t_player *player,
	t_cub *cub,
	double move_speed
)
{
	double		new_pos_x;
	double		new_pos_y;

	new_pos_x = (player->pos.x - player->dir.y * move_speed);
	new_pos_y = (player->pos.y + player->dir.x * move_speed);
	if (cub->worldmap[(int)new_pos_x][(int)(player->pos.y)] == '0')
		player->pos.x = new_pos_x;
	if (cub->worldmap[(int)(player->pos.x)][(int)new_pos_y] == '0')
		player->pos.y = new_pos_y;
}
