/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:28:56 by ukim              #+#    #+#             */
/*   Updated: 2021/01/14 20:34:09 by ukim             ###   ########.fr       */
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

static char		**read_map_file_to_array(char *path)
{
	int			fd;
	char		*line;
	char		*one_line;
	char		**stack;
	char		*tmp;

	fd = open(path, O_RDONLY);
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
	check_cub_file(stack);
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
	else if (ft_strcmp(tmp[0], "ST") == 0)
		cub->st_path = ft_strdup(tmp[1]);
	else if (ft_strcmp(tmp[0], "FT") == 0)
		cub->ft_path = ft_strdup(tmp[1]);
	else
		exit_program(ARGUMENT_ERROR);
}

static void		set_cub_backgrounds(char *cub_line, t_cub *cub)
{
	int			i;

	i = 1;
	if (!check_color_valid(cub_line))
		exit_program("Color value is invalid");
	if (ft_strncmp(cub_line, "F", 1) == 0)
	{
		while (cub_line[i])
			cub->floor_color = cub->floor_color * 256 +
				ft_atoi(&cub_line[i], &i);
	}
	else if (ft_strncmp(cub_line, "C", 1) == 0)
	{
		while (cub_line[i])
			cub->ceiling_color = cub->ceiling_color * 256 +
				ft_atoi(&cub_line[i], &i);
	}
}

void			set_cub(t_window *window, char *path)
{
	char		**cub_file;
	int			i;
	char		**tmp;

	cub_file = read_map_file_to_array(path);
	i = -1;
	while (++i < 3 + TEX_CNT)
	{
		tmp = ft_split(cub_file[i], ' ');
		if (*tmp[0] == 'R')
			set_screen_size(&cub_file[i][1], window->cub);
		else if (!ft_strncmp("ST", *tmp, 2) || !ft_strncmp("FT", *tmp, 2))
			exit_program(ARGUMENT_ERROR);
		else if (ft_strlen(tmp[0]) == 2 || *tmp[0] == 'S')
			set_cub_textures_path(tmp, window->cub);
		else if (*tmp[0] == 'F' || *tmp[0] == 'C')
			set_cub_backgrounds(cub_file[i], window->cub);
		else
			exit_program(ARGUMENT_ERROR);
		free_array(tmp);
	}
	set_cub_worldmap(cub_file, window);
	free_array(cub_file);
}
