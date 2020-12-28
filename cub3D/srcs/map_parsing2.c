/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-eunju <kim-eunju@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:09:26 by kim-eunju         #+#    #+#             */
/*   Updated: 2020/12/28 18:13:32 by kim-eunju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			fill_one_line_worldmap(char *line, t_window *window, int idx)
{
	int			j;
	int			pos_cnt;

	j = 0;
	pos_cnt = 0;
	while (j < window->cub->map_col)
	{
		if (j < (int)ft_strlen(line) && ft_isdigit(line[j]))
		{
			window->cub->worldmap[idx - 8][j] = line[j];
			if (line[j] == '2')
				window->cub->sprite_cnt++;
		}
		else
		{
			if (check_player_in_map(line[j]))
			{
				window->cub->p_direction = line[j];
				window->player->pos.x = (double)j + 0.5;
				window->player->pos.y = (double)idx + 0.5;
				pos_cnt++;
				window->cub->worldmap[idx - 8][j] = '0';
			}
			else
				window->cub->worldmap[idx - 8][j] = 'N';
		}
		j++;
	}
	window->cub->worldmap[idx - 8][j] = '\0';
	if (pos_cnt > 1)
		exit_program("Player is not identifiabl");
}

void			make_worldmap(char **line, t_window *window)
{
	int			idx;
	int			i;

	if (!(window->cub->worldmap = (char **)malloc(sizeof(char *) * (window->cub->map_row + 1))))
		exit_program(MEMORY_ALLOC_ERROR);
	idx = 8;
	i = 0;
	while (line[idx] && i < window->cub->map_row)
	{
		if (!(window->cub->worldmap[i++] = (char *)malloc(sizeof(char) * (window->cub->map_col + 1))))
			exit_program(MEMORY_ALLOC_ERROR);
		fill_one_line_worldmap(line[idx], window, idx);
		idx++;
	}
	window->cub->worldmap[window->cub->map_row] = NULL;
}

void			set_cub_worldmap(char **line, t_window *window)
{
	int			max_width;
	int			map_height;
	int			idx;

	idx = 8;
	map_height = 0;
	max_width = 0;
	while(line[idx])
	{
		if (max_width < (int)ft_strlen(line[idx]))
			max_width = (int)ft_strlen(line[idx]);
		idx++;
		map_height++;
	}
	window->cub->map_row = map_height;
	window->cub->map_col = max_width - 1;
	make_worldmap(line, window);
}

int				check_player_in_map(char c)
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