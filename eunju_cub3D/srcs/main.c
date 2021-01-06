/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekim <ekim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 22:39:57 by ekim              #+#    #+#             */
/*   Updated: 2020/12/23 17:07:02 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		draw(t_window *window)
{
	int			x;
	int			y;

	y = 0;
	while (y < window->cub->res_height)
	{
		x = 0;
		while (x < window->cub->res_width)
		{
			window->pimg->data[y * window->pimg->width + x] = \
				window->buffer[y][x];
			x++;
		}
		y++;
	}
	if (window->save == 0)
		mlx_put_image_to_window(window->mlx, window->win, \
								window->pimg->img, 0, 0);
}

static int		main_loop(void *param)
{
	t_window	*window;

	window = (t_window *)param;

	key_manager(window);
	raycasting(window);
	draw(window);
	return (SUCCESS);
}

int				main(int argc, char **argv)
{
	t_window	*window;

	if (!(window = (t_window *)malloc(sizeof(t_window))))
	 	exit_program(MEMORY_ALLOC_ERROR);
	if (argc == 2 && ft_strcmp(argv[1], "map.cub") == 0)
	{
		init_window(window, argv[1]);
		mlx_hook(window->win, KEY_PRESS, 0, &key_press, window);
		mlx_hook(window->win, KEY_RELEASED, 1, &key_released, window);
		mlx_hook(window->win, KEY_EXIT, 1L<<17, &destroy_window, window);
		mlx_loop_hook(window->mlx, main_loop, window);
		mlx_loop(window->mlx);
	}
	else if (argc == 3 && ft_strcmp(argv[2], "--save") == 0)
		take_screenshot(window, argv[1]);
	else
		exit_program("Invalid arguments were given.");
	return (0);
}