/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekim <ekim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:28:51 by ekim              #+#    #+#             */
/*   Updated: 2020/12/23 17:20:33 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			init_img(t_img *img)
{
	img->img = 0;
	img->data = 0;
	img->bpp = 0;
	img->line_length = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}

void			init_sprite(t_window *window)
{
	int			s_cnt;
	int			idx;
	int			x;
	int			y;

	s_cnt = window->cub->sprite_cnt;
	if (!(window->sprites = (t_sprite **)malloc(sizeof(t_sprite*) * s_cnt)))
		exit_program(MEMORY_ALLOC_ERROR);
	idx = 0;
	while (idx < s_cnt)
		if (!(window->sprites[idx++] = (t_sprite*)malloc(sizeof(t_sprite))))
			exit_program(MEMORY_ALLOC_ERROR);
	if (!(window->d_sprites = (t_d_sprites*)malloc(sizeof(t_d_sprites))))
		exit_program(MEMORY_ALLOC_ERROR);
	idx = 0;
	y = -1;
	while (++y < window->cub->map_row)
	{
		x = -1;
		while (++x < window->cub->map_col)
			if (window->cub->worldmap[y][x] == '2')
			{
				window->sprites[idx]->y = (double)x + 0.5;
				window->sprites[idx++]->x = (double)y + 0.5;
				window->cub->worldmap[y][x] = '0';
			}
	}
}

void			init_struct_window(t_window *window)
{
	int			i;

	i = 0;
	while (i < 5)
	{
		window->img[i] = (t_img*)malloc(sizeof(t_img));
		init_img(window->img[i++]);
	}
	if (!(window->pimg = (t_img *)malloc(sizeof(t_img))))
		exit_program(MEMORY_ALLOC_ERROR);
	init_img(window->pimg);
	if (!(window->player = (t_player *)malloc(sizeof(t_player))))
		exit_program(MEMORY_ALLOC_ERROR);
	init_player(window->player);
	if (!(window->ray = (t_ray *)malloc(sizeof(t_ray))))
		exit_program(MEMORY_ALLOC_ERROR);
	init_ray(window->ray);
	if (!(window->cub = (t_cub *)malloc(sizeof(t_cub))))
		exit_program(MEMORY_ALLOC_ERROR);
	init_cub(window->cub);
	if (!(window->key = (t_key *)malloc(sizeof(t_key))))
		exit_program(MEMORY_ALLOC_ERROR);
	init_key(window->key);
	window->rotSpeed = 0.05;
	window->moveSpeed = 0.1;
	window->save = 0;
}

void			make_buffer(t_window *window, int w, int h)
{
	int			i;

	if (!(window->ray->z_buffer = (double *)malloc(sizeof(double) * w)))
		exit_program(MEMORY_ALLOC_ERROR);
	ft_bzero(window->ray->z_buffer, sizeof(double) * w);
	if (!(window->buffer = (unsigned int **)malloc(sizeof(unsigned int *) * h)))
		exit_program(MEMORY_ALLOC_ERROR);
	i = 0;
	while (i < h)
		if (!(window->buffer[i++] = (unsigned int *)malloc(sizeof(unsigned int) * w)))
			exit_program(MEMORY_ALLOC_ERROR);
}

void			init_window(t_window *window, char *path)
{
	int			width;
	int			height;

	init_struct_window(window);
	if (!(window->mlx = mlx_init()))
		exit_program("mlx_init error");
	if (!set_cub(window, path))
		exit_program("invalid map");
	width = window->cub->res_width;
	height = window->cub->res_height;
	init_sprite(window);
	set_player_dir_plane_coord(window);
	if (window->save == 0)
		window->win = mlx_new_window(window->mlx, width, height, "cub3D");
	load_texture(window);
	if (!(window->pimg->img = mlx_new_image(window->mlx, width, height)))
		exit_program("mlx_new_image error");
	window->pimg->data = (unsigned int *)mlx_get_data_addr(window->pimg->img, \
		&window->pimg->bpp, &window->pimg->line_length, &window->pimg->endian);
	window->pimg->width = width;
	window->pimg->height = height;
	make_buffer(window, width, height);
}