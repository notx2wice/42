/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-eunju <kim-eunju@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 23:36:02 by kim-eunju         #+#    #+#             */
/*   Updated: 2021/01/06 20:45:47 by kim-eunju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				check_color_valid(char **tmp)
{
	int			i;
	int			dot_cnt;
	char		**color;

	i = 0;
	dot_cnt = 0;
	while (tmp[i])
		i++;
	if (i != 2)
		return (0);
	color = ft_split(tmp[1], ',');
	i = -1;
	while (++i < 3 && color[i])
		if (ft_atoi(color[i]) > 256 || ft_atoi(color[i]) < 0)
		{
			free(color);
			return (0);
		}
	free(color);
	if (i != 3)
		return (0);
	return (SUCCESS);
}

int				map_size_check(t_window *window, int x, int y)
{
	if (x <= 0 || x > window->cub->map_col)
		return (1);
	if (y <= 0 || y > window->cub->map_row)
		return (1);
	return (0);
}

int				**make_visited_array(t_window *window)
{
	int			**visited;
	int			x;
	int			y;
	int			i;

	i = 0;
	if (!(visited = (int**)malloc(sizeof(int*) * window->cub->map_row)))
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

void			dfs(int **v, int x, int y, t_window *window, int *res)
{
	int			dx[4] = {0, 0, 1, -1};
	int			dy[4] = {-1, 1, 0, 0};
	int			i;
	int			tx;
	int			ty;

	if (window->cub->worldmap[x][y] == 'N' || map_size_check(window, x, y))
	{
		*res = 0;
		return ;
	}
	i = -1;
	while (++i < 4)
	{
		tx = x + dx[i];
		ty = y + dy[i];
		if (v[tx][ty] == 0 && window->cub->worldmap[tx][ty] != '1')
		{
			v[tx][ty] = 1;
			dfs(v, tx, ty, window, res);
		}
	}
}

int				check_wall_valid(t_window *window)
{
	int			i;
	int			res;
	int			**visited;
	int			px;
	int			py;

	i = 0;
	res = 1;
	visited = make_visited_array(window);
	px = (int)window->player->pos.x;
	py = (int)window->player->pos.y;
	visited[px][py] = 1;
	dfs(visited, px, py, window, &res);
	i = 0;
	while (i < window->cub->map_row)
		free(visited[i++]);
	free(visited);
	return (res);
}
