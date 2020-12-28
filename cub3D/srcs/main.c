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

void		pixel_put_to_image(int color, int x, int y, t_img *img)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];
	img->data[y * img->line_length + x * img->bpp / 8] = r;
	img->data[y * img->line_length + x * img->bpp / 8 + 1] = g;
	img->data[y * img->line_length + x * img->bpp / 8 + 2] = b;
}

void			draw(t_window *window)
{
	int			x;
	int			y;

	y = 0;
	while (y < window->cub->res_height)
	{
		x = 0;
		while (x < window->cub->res_width)
		{
			pixel_put_to_image(window->buffer[y][x], x, y, window->pimg);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(window->mlx, window->win, window->pimg->img, 0, 0);
}

// void			calc(t_window *window)
// {
// 	int			x;
// 	int			i;

// 	x =	0;
// 	while (x < window->cub->res_width)
// 		floor_ceiling_to_buffer(window, x++);
// 	x = 0;
// 	while (x < window->cub->res_width)
// 		wall_to_buffer(window, x++);
// 	sortSprites(window);
// 	i = 0;
// 	while(i < window->cub->sprite_cnt)
// 		draw_sprite(window, i++);
// }

int				main_loop(t_window *window)
{
	raycasting(window);
	draw(window);
	return (0);
}

int				key_press(int key, t_window *window)
{
	if (key == KEY_W)
		move_player_forward(window->player, window->cub, window->moveSpeed);
	else if (key == KEY_A)
		move_player_left(window->player, window->cub, window->moveSpeed);
	else if (key == KEY_S)
		move_player_backward(window->player, window->cub, window->moveSpeed);
	else if (key == KEY_D)
		move_player_right(window->player, window->cub, window->moveSpeed);
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		rotate_player(window->player, window->rotSpeed, key);
	else if (key == KEY_ESC)
	{
		free_window(window);
		exit(0);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_window	*window;

	if (!(window = (t_window *)malloc(sizeof(t_window))))
	 	exit_program(MEMORY_ALLOC_ERROR);
	if (argc == 2 && ft_strcmp(argv[1], "map.cub") == 0)
	{
		init_window(window, argv[1]);
		// init_sprite(window);
		mlx_hook(window->win, KEY_PRESS, 1, &key_press, window);
		mlx_loop_hook(window->mlx, main_loop, window);
		mlx_loop(window->mlx);
	}
/*
	else if (argc == 3 && ft_strcmp(argv[2],"--save") == 0)
	{
		init_window(window, argv[1]);
		init_temp(window);
		init_sprite(window);
		calc(window);
		draw(window);
		save_bmp(window);
		exit(0);
	}
*/
	// else
	// 	exit_program("A .cub file path not given");
	return (0);
}
