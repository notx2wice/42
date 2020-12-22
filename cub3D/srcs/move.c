/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekim <ekim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 20:27:15 by ekim              #+#    #+#             */
/*   Updated: 2020/12/19 20:27:15 by ekim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		rotate_player(t_player *player, int rotSpeed, int keycode)
{
	double	oldDir_x;
	double	oldPlane_x;

	oldDir_x = player->dir.x;
	oldPlane_x = player->plane.x;
	if (keycode == KEY_LEFT)
	{
		player->dir.x = player->dir.x * cos(rotSpeed) \
			- (player->dir.y * sin(rotSpeed));
		player->dir.y = (oldDir_x * sin(rotSpeed)) \
			+ (player->dir.y * cos(rotSpeed));
		player->plane.x = (player->plane.x *cos(rotSpeed)) \
			- (player->plane.y * sin(rotSpeed));
		player->plane.y = (oldPlane_x * sin(rotSpeed)) \
			+ (player->plane.y * cos(rotSpeed));
	}
	else if (keycode == KEY_RIGHT)
	{
		player->dir.x = player->dir.x * cos(-rotSpeed) \
			- (player->dir.y * sin(-rotSpeed));
		player->dir.y = (oldDir_x * sin(-rotSpeed)) \
			+ (player->dir.y * cos(-rotSpeed));
		player->plane.x = (player->plane.x *cos(-rotSpeed)) \
			- (player->plane.y * sin(-rotSpeed));
		player->plane.y = (oldPlane_x * sin(-rotSpeed)) \
			+ (player->plane.y * cos(-rotSpeed));
	}
}

void		move_player_forward(t_player *player, t_cub *cub, int moveSpeed)
{
	int		new_pos_x;
	int		new_pos_y;

	new_pos_x = (int)(player->pos.x + player->dir.x * moveSpeed);
	new_pos_y = (int)(player->pos.y + player->dir.y * moveSpeed);
	if (cub->worldmap[new_pos_x][(int)(player->pos.y)] == '0')
		player->pos.x += player->dir.x * moveSpeed;
	if (cub->worldmap[(int)(player->pos.x)][new_pos_y] == '0')
		player->pos.y += player->dir.y * moveSpeed;
}

void		move_player_backward(t_player *player, t_cub *cub, int moveSpeed)
{
	int		new_pos_x;
	int		new_pos_y;

	new_pos_x = (int)(player->pos.x - player->dir.x * moveSpeed);
	new_pos_y = (int)(player->pos.y - player->dir.y * moveSpeed);
	if (cub->worldmap[new_pos_x][(int)(player->pos.y)] == '0')
		player->pos.x -= player->dir.x * moveSpeed;
	if (cub->worldmap[(int)(player->pos.x)][new_pos_y] == '0')
		player->pos.y -= player->dir.y * moveSpeed;
}

void		move_player_right(t_player *player, t_cub *cub, int moveSpeed)
{
	int		new_pos_x;
	int		new_pos_y;

	new_pos_x = (int)(player->pos.x + player->dir.x * moveSpeed);
	new_pos_y = (int)(player->pos.y - player->dir.y * moveSpeed);
	if (cub->worldmap[new_pos_x][(int)(player->pos.y)] == '0')
		player->pos.x += player->dir.y * moveSpeed;
	if (cub->worldmap[(int)(player->pos.x)][new_pos_y] == '0')
		player->pos.y -= player->dir.x * moveSpeed;
}

void		move_player_left(t_player *player, t_cub *cub, int moveSpeed)
{
	int		new_pos_x;
	int		new_pos_y;

	new_pos_x = (int)(player->pos.x - player->dir.x * moveSpeed);
	new_pos_y = (int)(player->pos.y + player->dir.y * moveSpeed);
	if (cub->worldmap[new_pos_x][(int)(player->pos.y)] == '0')
		player->pos.x -= player->dir.y * moveSpeed;
	if (cub->worldmap[(int)(player->pos.x)][new_pos_y] == '0')
		player->pos.y += player->dir.x * moveSpeed;
}