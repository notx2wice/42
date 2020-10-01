/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 13:54:15 by ukim              #+#    #+#             */
/*   Updated: 2020/08/09 15:18:14 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	int_print(int answer[]);
void	dfs(int level, int answer[], int visited[]);
void	ft_print_comb(void);

void	dfs(int level, int answer[], int visited[])
{
	int	count;

	count = 0;
	if (level == 4)
		int_print(answer);
	else
	{
		count = answer[level - 1] + 1;
		while (count <= 9)
		{
			if (visited[count] == 0)
			{
				visited[count] = 1;
				answer[level] = count;
				dfs(level + 1, answer, visited);
				visited[count] = 0;
			}
			count++;
		}
	}
}

void	int_print(int answer[])
{
	int		count;
	char	c;
	char	comma;
	char	space;
	char	backn;

	count = 1;
	c = '0';
	comma = ',';
	space = ' ';
	backn = '\n';
	while (count < 4)
	{
		c = answer[count] + 48;
		write(1, &c, 1);
		count++;
	}
	if (answer[1] == 7 && answer[2] == 8 && answer[3] == 9)
		return ;
	else
	{
		write(1, &comma, 1);
		write(1, &space, 1);
	}
}

void	visited_to_zero(int visited[])
{
	int	a;

	a = 0;
	while (a < 10)
	{
		visited[a] = 0;
		a++;
	}
}

void	ft_print_comb(void)
{
	int visited[10];
	int answer[4];

	answer[0] = -1;
	visited_to_zero(visited);
	dfs(1, answer, visited);
}
