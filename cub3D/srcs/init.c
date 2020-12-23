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
	init_coord_d(player->pos);
	init_coord_d(player->dir);
	init_coord_d(player->plane);
}

/*
** void			init_sprite(t_sprite *sprite)
** {
** 	if (!(sprite = malloc(sizeof(t_sprite))))
** 		exit_program(MEMORY_ALLOC_ERROR);
** 	sprite.x = 0;
** 	sprite.y = 0;
** 	sprite.distance = 0;
** }
*/

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

void        init_ray(t_ray *ray)
{
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
	ray->tex_num = 0;
	ray->tex_x = 0;
	ray->tex_y = 0;
	ray->wall_x = 0;
}

void		init_img(t_img *img)
{
	img->img = "";
	img->data = "";
	img->bpp = 0;
	img->line_length = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}

void		init_struct_window(t_window *window)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		window->img[i] = (t_img*)malloc(sizeof(t_img));
		init_img(window->img[i++]);
	}
	if (!(window->player = (t_player *)malloc(sizeof(t_player))))
		exit_program(MEMORY_ALLOC_ERROR);
	init_player(window->player);
	if (!(window->ray = (t_ray *)malloc(sizeof(t_ray))))
		exit_program(MEMORY_ALLOC_ERROR);
	init_ray(window->ray);
	if (!(window->cub = (t_cub *)malloc(sizeof(t_cub))))
		exit_program(MEMORY_ALLOC_ERROR);
	init_cub(window->cub);

	window->rotSpeed = 0.05;
	window->moveSpeed = 0.05;
}

void		init_window(t_window *window, char *path)
{
	int		i;

	init_struct_window(window);
	window->mlx = mlx_init();
	set_cub(window, path);
	printf("cub->res_width : %d\ncub->res_height: %d\n", window->cub->res_width, window->cub->res_height);
	window->win = mlx_new_window(window->mlx, window->cub->res_width, window->cub->res_height, "cub3D");
	window->pimg.img = mlx_new_image(window->mlx, window->cub->res_width, window->cub->res_height);
	window->pimg.data = mlx_get_data_addr(window->pimg.img, &window->pimg.bpp, &window->pimg.line_length, &window->pimg.endian);
	if (!(window->buffer = (int **)malloc(sizeof(int *) * window->cub->res_height)))
		exit_program(MEMORY_ALLOC_ERROR);
	i = 0;
	while (i < window->cub->res_height)
	{
		if (!(window->buffer[i] = (int *)malloc(sizeof(int) * window->cub->res_width)))
			exit_program(MEMORY_ALLOC_ERROR);
		i++;
	}
	load_texture(window);
}
