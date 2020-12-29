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

int			key_manager(t_window *window)
{
	if (window->key->forward == 1)
		move_player_forward(window->player, window->cub, window->moveSpeed);
	else if (window->key->left == 1)
		move_player_left(window->player, window->cub, window->moveSpeed);
	else if (window->key->backward == 1)
		move_player_backward(window->player, window->cub, window->moveSpeed);
	else if (window->key->right == 1)
		move_player_right(window->player, window->cub, window->moveSpeed);
	else if (window->key->turn_left == 1)
		rotate_player(window->player, window->rotSpeed, KEY_LEFT);
	else if (window->key->turn_right == 1)
		rotate_player(window->player, window->rotSpeed, KEY_RIGHT);
	return (SUCCESS);
}

void		rotate_player(t_player *player, double rotSpeed, int keycode)
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

void			move_player_forward(t_player *player, t_cub *cub, double moveSpeed)
{
	double		new_pos_x;
	double		new_pos_y;

	new_pos_x = (player->pos.x + player->dir.x * moveSpeed);
	new_pos_y = (player->pos.y + player->dir.y * moveSpeed);
	printf("worldmap : %c\n", cub->worldmap[(int)new_pos_x][(int)(player->pos.y)]);

	if (cub->worldmap[(int)new_pos_x][(int)(player->pos.y)] == '0')
	{
		printf("before : pos.x - %f\n", player->pos.x);
		player->pos.x += player->dir.x * moveSpeed;
		printf("player->dir.x - %f ", player->dir.x);
		printf("moveSpeed - %f\n", moveSpeed);
		printf("after : pos.x - %f\n", player->pos.x);
	}
	if (cub->worldmap[(int)(player->pos.x)][(int)new_pos_y] == '0')
		player->pos.y += player->dir.y * moveSpeed;

}

void		move_player_backward(t_player *player, t_cub *cub, double moveSpeed)
{
	double		new_pos_x;
	double		new_pos_y;

	new_pos_x = (player->pos.x - player->dir.x * moveSpeed);
	new_pos_y = (player->pos.y - player->dir.y * moveSpeed);
	if (cub->worldmap[(int)new_pos_x][(int)(player->pos.y)] == '0')
		player->pos.x -= player->dir.x * moveSpeed;
	if (cub->worldmap[(int)(player->pos.x)][(int)new_pos_y] == '0')
		player->pos.y -= player->dir.y * moveSpeed;
}

void		move_player_right(t_player *player, t_cub *cub, double moveSpeed)
{
	double		new_pos_x;
	double		new_pos_y;

	new_pos_x = (player->pos.x + player->dir.x * moveSpeed);
	new_pos_y = (player->pos.y - player->dir.y * moveSpeed);
	if (cub->worldmap[(int)new_pos_x][(int)(player->pos.y)] == '0')
		player->pos.x += player->dir.y * moveSpeed;
	if (cub->worldmap[(int)(player->pos.x)][(int)new_pos_y] == '0')
		player->pos.y -= player->dir.x * moveSpeed;
}

void		move_player_left(t_player *player, t_cub *cub, double moveSpeed)
{
	double		new_pos_x;
	double		new_pos_y;

	new_pos_x = (player->pos.x - player->dir.x * moveSpeed);
	new_pos_y = (player->pos.y + player->dir.y * moveSpeed);
	if (cub->worldmap[(int)new_pos_x][(int)(player->pos.y)] == '0')
		player->pos.x -= player->dir.y * moveSpeed;
	if (cub->worldmap[(int)(player->pos.x)][(int)new_pos_y] == '0')
		player->pos.y += player->dir.x * moveSpeed;
}