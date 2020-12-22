/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekim <ekim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:14:55 by ekim              #+#    #+#             */
/*   Updated: 2020/12/15 20:14:55 by ekim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			main(int ac, char **av)
{
	int		map_fd;
	t_cub	cub;

	if (ac < 2 || ac > 3)
		exit_program(ARGUMENT_ERROR);
	if (ft_strcmp(av[1], "map.cub"))
		exit_program(ARGUMENT_ERROR);
	if (ft_strcmp(av[2], "--save"))
		exit_program(ARGUMENT_ERROR);
	if ((map_fd = open(av[1], O_RDONLY)) < 0)
		exit_program(OPEN_ERROR);

	map_fd = open("../map.cub", O_RDONLY);
	set_cub(&cub, map_fd);
	 
	printf("%d\n", cub.res_width);
	printf("%d\n", cub.res_height);
	printf("%s\n", cub.ea_path);
	printf("%d\n", cub.map_col);
	printf("%c\n", cub.p_direction);
	printf("%f\n", cub.player->pos.x);
	printf("%f\n", cub.player->pos.y);

    free_int_array(cub.worldmap, cub.map_row);
}