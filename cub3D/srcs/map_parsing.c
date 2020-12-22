/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekim <ekim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:28:56 by ekim              #+#    #+#             */
/*   Updated: 2020/12/15 19:28:56 by ekim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char			**read_map_file_to_array(int fd)
{
	char		*line;
	char		*one_line;
	char		**stack;
	char		*tmp;

	one_line = ft_strdup("");
	while (get_next_line(fd, &line))
	{
		if (ft_isalnum(*line) || *line == ' ')
		{
			tmp = ft_free_strjoin(one_line, line);
			one_line = ft_strjoin(tmp, "\n");
			free(tmp);
		}
		else
			free(line);
	}
	tmp = ft_free_strjoin(one_line, line);
	stack = ft_split(tmp, '\n');
	free(tmp);
	close(fd);
	return (stack);
}

void			set_cub_textures_path(char **tmp, t_cub *cub)
{
	if (ft_strcmp(tmp[0], "NO") == 0)
		cub->no_path = ft_strdup(tmp[1]);
	else if (ft_strcmp(tmp[0], "SO") == 0)
		cub->so_path = ft_strdup(tmp[1]);
	else if (ft_strcmp(tmp[0], "EA") == 0)
		cub->ea_path = ft_strdup(tmp[1]);
	else if (ft_strcmp(tmp[0], "WE") == 0)
		cub->we_path = ft_strdup(tmp[1]);
	else if (ft_strcmp(tmp[0], "S") == 0)
		cub->sprite_path = ft_strdup(tmp[1]);
	else
		exit_program(ARGUMENT_ERROR);
}

void			set_cub_backgrounds(char **tmp, t_cub *cub)
{
	char		**color;
	int			i;

	i = 0;
	color = ft_split(tmp[1], ',');
	if (ft_strcmp(tmp[0], "F") == 0)
	{
		while (color[i])
			cub->floor_color = cub->floor_color * 256 + ft_atoi(color[i++]);
	}
	else if (ft_strcmp(tmp[0], "C") == 0)
	{
		while (color[i])
			cub->ceiling_color = cub->ceiling_color * 256 + ft_atoi(color[i++]);
	}
	free_char_array(color);
}

int				*fill_one_line_worldmap(char *line, t_window *window, int idx, int *pos_cnt)
{
	int			j;
	char		*tmp;

	j = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * (window->cub->map_col + 1))))
		exit_program(MEMORY_ALLOC_ERROR);
	while (j < window->cub->map_col)
	{
		if (j < (int)ft_strlen(line) && ft_isdigit(line[j]))
		{
			tmp[j] = line[j];
			if (line[j] == '2')
				window->cub->sprite_cnt++;
		}
		else
		{
			if (ft_isalpha(line[j]))
			{
				window->cub->p_direction = line[j];
				window->player->pos.x = (double)j + 0.5;
				window->player->pos.y = (double)idx + 0.5;
				tmp[j] = '0';
				(*pos_cnt)++;
			}
			else
				tmp[j] = 'N';
		}
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

void			make_worldmap(char **line, t_window *window)
{
	char		**map;
	int			pos_cnt;
	int			idx;
	char		*tmp;

	pos_cnt = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (window->cub->map_row + 1))))
		exit_program(MEMORY_ALLOC_ERROR);
	idx = 8;
	while (line[idx])
	{
		tmp = fill_one_line_worldmap(line[idx], window, idx, &pos_cnt);
		map[idx - 8] = tmp;
		idx++;
	}
	if (pos_cnt > 1)
		exit_program("Player's position is not identifiable");
	map[idx - 8] = NULL;
	window->cub->worldmap = map;
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
	window->cub->map_col = max_width;
	make_worldmap(line, window);
}

int				check_player_direction(t_cub *cub)
{
	char		*direction;

	direction = "EWSN";
	while (*direction)
	{
		if (cub->p_direction == *direction)
			return (1);
		direction++;
	}
	return (0);
}

int				set_cub(t_window *window, char *path)
{
	char		**cub_file;
	int			i;
	char		**tmp;
	char		**map;
	int			j;
	int			fd;
	// read file by fd from main. Return ERROR if failed.b
	fd = open(path, O_RDONLY);
	cub_file = read_map_file_to_array(fd);
	i = 0;
	while (i < 8)
	{
		tmp = ft_split(cub_file[i], ' ');
		if (*tmp[0] == 'R')
		{
			window->cub->res_width = ft_atoi(tmp[1]);
			window->cub->res_height = ft_atoi(tmp[2]);
		}
		else if (ft_strncmp(tmp[1], "../", 3) == 0)
			set_cub_textures_path(tmp, window->cub);
		else if (*tmp[0] == 'F' || *tmp[0] == 'C')
			set_cub_backgrounds(tmp, window->cub);
		else
			exit_program(ARGUMENT_ERROR);
		i++;
		free_char_array(tmp);
	}
	set_cub_worldmap(cub_file, window);
	if (!check_player_direction(window->cub))
		exit_program("Player's looking direction is invalid");
	free_char_array(cub_file);
	return (1);
}