/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_screen_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:52:47 by ukim              #+#    #+#             */
/*   Updated: 2021/01/14 20:35:14 by ukim             ###   ########.fr       */
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
	if (width > 2560)
		cub->res_width = 2560;
	else
		cub->res_width = width;
	height = ft_atoi(&line[idx], &idx);
	if (height > 1440)
		cub->res_height = 1440;
	else
		cub->res_height = height;
	if (height <= 0 || width <= 0)
		exit_program("Screen size error");
}
