/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-eunju <kim-eunju@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 02:22:57 by kim-eunju         #+#    #+#             */
/*   Updated: 2020/12/29 19:47:24 by kim-eunju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				event_destroy_window(void *param)
{
	t_window 	*window;

	window = (t_window *)param;
	mlx_destroy_window(window->mlx, window->win);
	exit(0);
	return (SUCCESS);
}

int				key_released(int key, void *param)
{
	t_window	*window;

	printf("key_released\n");
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
	printf("key_press\n");
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