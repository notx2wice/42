/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_screen_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:52:47 by ukim              #+#    #+#             */
/*   Updated: 2021/01/16 02:26:50 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			set_screen_size(char *line, t_cub *cub)
{
	int			width;
	int			height;
	int			idx;

	idx = 0;
	width = ft_atoi(line, &idx);
	if (width > 1000)
		cub->res_width = 1000;
	else
		cub->res_width = width;
	height = ft_atoi(&line[idx], &idx);
	if (height > 800)
		cub->res_height = 800;
	else
		cub->res_height = height;
	if (height <= 0 || width <= 0)
		exit_program("Screen size error");
}
