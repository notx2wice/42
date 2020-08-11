/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:11:25 by ukim              #+#    #+#             */
/*   Updated: 2020/08/09 15:18:43 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(int c)
{
	char	x;

	x = c + 48;
	write(1, &x, 1);
}

void	print_ans(int n, int answer[])
{
	int c;

	c = 1;
	while (c <= n)
	{
		putchar(answer[c]);
		c++;
	}
	if (answer[1] == 10 - n)
		return ;
	else
		write(1, ", ", 2);
}

void	dfs(int n, int level, int answer[], int visited[])
{
	int count;

	count = 0;
	if (level == n + 1)
	{
		print_ans(n, answer);
	}
	else
	{
		count = answer[level - 1] + 1;
		while (count <= 9)
		{
			if (visited[count] == 0)
			{
				visited[count] = 1;
				answer[level] = count;
				dfs(n, level + 1, answer, visited);
				visited[count] = 0;
			}
			count++;
		}
	}
}

void	ft_print_combn(int n)
{
	int c;
	int	answer[11];
	int	visited[10];

	c = 0;
	answer[0] = -1;
	while (c <= 9)
	{
		visited[c] = 0;
		c++;
	}
	dfs(n, 1, answer, visited);
}
