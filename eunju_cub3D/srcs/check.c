/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-eunju <kim-eunju@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 23:36:02 by kim-eunju         #+#    #+#             */
/*   Updated: 2021/01/07 21:46:53 by kim-eunju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				check_color_valid(char *line)
{
	int			i;
	int			j;
	int			res;
	int			ret;

	i = -1;
	j = 0;
	res = 1;
	while (line[++i])
		if (line[i] == ',')
			j++;
	if (j != 2)
		res = 0;
	i = 0;
	j = 1;
	while (j < (int)ft_strlen(line))
	{
		ret = ft_atoi(&line[j], &j);
		i++;
		if (ret > 255 || ret < 0)
			res = 0;
	}
	if (i != 3)
		res = 0;
	return (res);
}

static int		**make_visited_array(t_window *window)
{
	int			**visited;
	int			x;
	int			y;
	int			i;

	i = 0;
	if (!(visited = (int **)malloc(sizeof(int *) * window->cub->map_row)))
		exit_program(MEMORY_ALLOC_ERROR);
	while (i < window->cub->map_row)
	{
		if (!(visited[i++] =
			(int *)malloc(sizeof(int) * window->cub->map_col)))
			exit_program(MEMORY_ALLOC_ERROR);
	}
	x = -1;
	while (++x < window->cub->map_row)
	{
		y = -1;
		while (++y < window->cub->map_col)
			visited[x][y] = 0;
	}
	return (visited);
}

static void		make_step_array(int *dx, int *dy)
{
	int			i;

	i = 0;
	dx[i] = 0;
	dy[i] = 1;
	while (++i < 4)
	{
		dx[i] = -1 * dy[i - 1];
		dy[i] = dx[i - 1];
	}
}

static void		dfs(int **visited, int x, int y, t_window *window)
{
	int			dx[4];
	int			dy[4];
	int			i;
	t_coord_i	tpos;

	if (window->cub->worldmap[x][y] == 'N' ||
		(x <= 0 || x > window->cub->map_col) ||
		(y <= 0 || y > window->cub->map_row))
	{
		window->visited_res = 0;
		return ;
	}
	make_step_array(dx, dy);
	i = -1;
	while (++i < 4)
	{
		tpos.x = x + dx[i];
		tpos.y = y + dy[i];
		if (visited[tpos.x][tpos.y] == 0 &&
			window->cub->worldmap[tpos.x][tpos.y] != '1')
		{
			visited[tpos.x][tpos.y] = 1;
			dfs(visited, tpos.x, tpos.y, window);
		}
	}
}

int				check_wall_valid(t_window *window)
{
	int			i;
	int			**visited;
	int			px;
	int			py;

	i = 0;
	window->visited_res = 1;
	visited = make_visited_array(window);
	px = (int)window->player->pos.x;
	py = (int)window->player->pos.y;
	visited[px][py] = 1;
	dfs(visited, px, py, window);
	i = 0;
	while (i < window->cub->map_row)
		free(visited[i++]);
	free(visited);
	return (window->visited_res);
}
