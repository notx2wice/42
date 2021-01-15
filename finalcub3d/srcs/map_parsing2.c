/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:09:26 by ukim              #+#    #+#             */
/*   Updated: 2021/01/14 20:34:34 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int		check_player_in_map(char c)
{
	char		*direction;
	int			i;

	i = 0;
	direction = "NEWS";
	while (direction[i])
	{
		if (c == direction[i])
			return (1);
		i++;
	}
	return (0);
}

static int		fill_player_and_worldmap_space
(
	char *line,
	t_window *window,
	int idx,
	int i
)
{
	int			pos_cnt;

	pos_cnt = 0;
	if ((int)ft_strlen(line) >= i && check_player_in_map(line[i]))
	{
		window->cub->p_direction = line[i];
		window->player->pos.y = (double)i + 0.5;
		window->player->pos.x = (double)idx - (TEX_CNT + 3) + 0.5;
		pos_cnt++;
		window->cub->worldmap[idx - (TEX_CNT + 3)][i] = '0';
	}
	else
		window->cub->worldmap[idx - (TEX_CNT + 3)][i] = 'X';
	return (pos_cnt);
}

static int		fill_one_line_worldmap
(
	char *line,
	t_window *window,
	int idx
)
{
	int			i;
	int			pos_cnt;

	i = 0;
	pos_cnt = 0;
	while (i < window->cub->map_col)
	{
		if (i < (int)ft_strlen(line) && ft_isdigit(line[i]))
		{
			window->cub->worldmap[idx - (TEX_CNT + 3)][i] = line[i];
			if (line[i] == '2')
				window->cub->sprite_cnt++;
		}
		else
			pos_cnt += fill_player_and_worldmap_space(line, window, idx, i);
		i++;
	}
	window->cub->worldmap[idx - (TEX_CNT + 3)][i] = '\0';
	return (pos_cnt);
}

static void		make_worldmap(char **line, t_window *window)
{
	int			idx;
	int			i;
	int			pos_cnt;

	pos_cnt = 0;
	if (!(window->cub->worldmap = (char **)malloc(sizeof(char *) *
		(window->cub->map_row + 1))))
		exit_program(MEMORY_ALLOC_ERROR);
	idx = 3 + TEX_CNT;
	i = 0;
	while (line[idx] && i < window->cub->map_row)
	{
		if (!(window->cub->worldmap[i++] = (char *)malloc(sizeof(char) *
			(window->cub->map_col + 1))))
			exit_program(MEMORY_ALLOC_ERROR);
		pos_cnt += fill_one_line_worldmap(line[idx], window, idx);
		idx++;
	}
	if (pos_cnt > 1 || pos_cnt <= 0)
		exit_program(MAP_ERROR);
	window->cub->worldmap[window->cub->map_row] = NULL;
}

void			set_cub_worldmap(char **line, t_window *window)
{
	int			max_width;
	int			map_height;
	int			idx;

	idx = 3 + TEX_CNT;
	map_height = 0;
	max_width = 0;
	while (line[idx])
	{
		if (max_width < (int)ft_strlen(line[idx]))
			max_width = (int)ft_strlen(line[idx]);
		idx++;
		map_height++;
	}
	window->cub->map_row = map_height;
	window->cub->map_col = max_width;
	make_worldmap(line, window);
	if (!check_wall_valid(window))
		exit_program(MAP_ERROR);
}
