/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-eunju <kim-eunju@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 02:22:57 by kim-eunju         #+#    #+#             */
/*   Updated: 2021/01/10 18:59:00 by kim-eunju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				key_manager(t_window *window)
{
	if (window->key->forward == 1)
		move_player_forward(window->player, window->cub, window->move_speed);
	else if (window->key->left == 1)
		move_player_left(window->player, window->cub, window->move_speed);
	else if (window->key->backward == 1)
		move_player_backward(window->player, window->cub, window->move_speed);
	else if (window->key->right == 1)
		move_player_right(window->player, window->cub, window->move_speed);
	else if (window->key->turn_left == 1)
		rotate_player(window->player, window->rot_speed, KEY_LEFT);
	else if (window->key->turn_right == 1)
		rotate_player(window->player, window->rot_speed, KEY_RIGHT);
	return (SUCCESS);
}

int				destroy_window(void *param)
{
	t_window	*window;

	window = (t_window *)param;
	mlx_destroy_window(window->mlx, window->win);
	free_window(window);
	exit(0);
	return (SUCCESS);
}

int				key_released(int key, void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (key == KEY_W && window->key->forward == 1)
		window->key->forward = 0;
	else if (key == KEY_S && window->key->backward == 1)
		window->key->backward = 0;
	else if (key == KEY_A && window->key->left == 1)
		window->key->left = 0;
	else if (key == KEY_D && window->key->right == 1)
		window->key->right = 0;
	else if (key == KEY_LEFT && window->key->turn_left == 1)
		window->key->turn_left = 0;
	else if (key == KEY_RIGHT && window->key->turn_right == 1)
		window->key->turn_right = 0;
	return (SUCCESS);
}

int				key_press(int key, void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (key == KEY_ESC)
	{
		free_window(window);
		exit(0);
	}
	else if (key == KEY_W && window->key->forward == 0)
		window->key->forward = 1;
	else if (key == KEY_S && window->key->backward == 0)
		window->key->backward = 1;
	else if (key == KEY_A && window->key->left == 0)
		window->key->left = 1;
	else if (key == KEY_D && window->key->right == 0)
		window->key->right = 1;
	else if (key == KEY_LEFT && window->key->turn_left == 0)
		window->key->turn_left = 1;
	else if (key == KEY_RIGHT && window->key->turn_right == 0)
		window->key->turn_right = 1;
	return (SUCCESS);
}
