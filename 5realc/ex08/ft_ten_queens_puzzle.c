/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 21:19:50 by ukim              #+#    #+#             */
/*   Updated: 2020/08/10 22:09:25 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int answer[])
{
	int		x;
	char	c;

	x = 0;
	while (x < 10)
	{
		c = answer[x] + '0';
		write(1, &c, 1);
		x++;
	}
	write(1, "\n", 1);
}

void	uncheck_visited(int visited[][11], int level, int idx)
{
	int x;
	int y;

	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			if (x == level || y == idx)
				visited[x][y]--;
			else if ((x - level) == (y - idx))
				visited[x][y]--;
			else if ((x - level) == -1 * (y - idx))
				visited[x][y]--;
			y++;
		}
		x++;
	}
}

void	check_visited(int visited[][11], int level, int idx)
{
	int x;
	int y;

	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			if (x == level || y == idx)
				visited[x][y]++;
			else if ((x - level) == (y - idx))
				visited[x][y]++;
			else if ((x - level) == -1 * (y - idx))
				visited[x][y]++;
			y++;
		}
		x++;
	}
}

void	dfs(int level, int answer[], int visited[][11], int *count)
{
	int idx;

	if (level == 10)
	{
		(*count)++;
		print(answer);
	}
	else
	{
		idx = 0;
		while (idx < 10)
		{
			if (visited[level][idx] == 0)
			{
				check_visited(visited, level, idx);
				answer[level] = idx;
				dfs(level + 1, answer, visited, count);
				uncheck_visited(visited, level, idx);
			}
			idx++;
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	int		count;
	int		answer[11];
	int		visited[11][11];
	int		x;
	int		y;

	x = 0;
	while (x < 11)
		answer[x++] = 0;
	x = 0;
	while (x < 11)
	{
		y = 0;
		while (y < 10)
		{
			visited[x][y] = 0;
			y++;
		}
		x++;
	}
	count = 0;
	dfs(0, answer, visited, &count);
	return (count);
}
