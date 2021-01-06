/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekim <ekim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:28:56 by ekim              #+#    #+#             */
/*   Updated: 2020/12/23 16:49:23 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		check_cub_file(char **lines)
{
	int			i;
	int			j;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (ft_isascii(lines[i][j]) == 0)
				lines[i][j] = '\0';
			j++;
		}
		i++;
	}
}

static char		**read_map_file_to_array(int fd)
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

static void		set_cub_textures_path(char **tmp, t_cub *cub)
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

static void		set_cub_backgrounds(char **tmp, t_cub *cub)
{
	char		**color;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!check_color_valid(tmp))
		exit_program("Color value is invalid");
	color = ft_split(tmp[1], ',');
	if (ft_strcmp(tmp[0], "F") == 0)
	{
		while (color[i])
			cub->floor_color = cub->floor_color * 256 + ft_atoi(color[i++]);
	}
	else if (ft_strcmp(tmp[0], "C") == 0)
	{
		while (color[i])
			cub->ceiling_color = \
				cub->ceiling_color * 256 + ft_atoi(color[i++]);
	}
	free_array(color);
}

int				set_cub(t_window *window, char *path)
{
	char		**cub_file;
	int			i;
	char		**tmp;
	int			fd;

	fd = open(path, O_RDONLY);
	cub_file = read_map_file_to_array(fd);
	check_cub_file(cub_file);
	i = -1;
	while (++i < 8)
	{
		tmp = ft_split(cub_file[i], ' ');
		if (*tmp[0] == 'R')
		{
			window->cub->res_width = ft_atoi(tmp[1]);
			window->cub->res_height = ft_atoi(tmp[2]);
		}
		else if (ft_strlen(tmp[0]) == 2 || *tmp[0] == 'S')
			set_cub_textures_path(tmp, window->cub);
		else if (*tmp[0] == 'F' || *tmp[0] == 'C')
			set_cub_backgrounds(tmp, window->cub);
		else
			exit_program(ARGUMENT_ERROR);
		free_array(tmp);
	}
	set_cub_worldmap(cub_file, window);
	free_array(cub_file);
	if (!check_wall_valid(window))
		exit_program("Map is invalid!");
	return (SUCCESS);
}