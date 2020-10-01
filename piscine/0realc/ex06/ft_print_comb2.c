/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:52:18 by ukim              #+#    #+#             */
/*   Updated: 2020/08/09 15:18:27 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	print_int(int temp[])
{
	char	a;
	char	b;
	int		c;

	c = 1;
	while (c < 3)
	{
		if (temp[c] < 10)
		{
			b = temp[c] + 48;
			putchar('0');
			putchar(b);
		}
		else
		{
			a = temp[c] / 10 + 48;
			b = temp[c] % 10 + 48;
			putchar(a);
			putchar(b);
		}
		if (c == 1)
			putchar(' ');
		c++;
	}
}

void	print_ans(int answer[])
{
	print_int(answer);
	if (answer[1] == 98 && answer[2] == 99)
	{
		return ;
	}
	else
	{
		putchar(',');
		putchar(' ');
	}
}

void	dfs(int level, int answer[], int visited[])
{
	int count;

	count = 0;
	if (level == 3)
	{
		print_ans(answer);
	}
	else
	{
		count = answer[level - 1] + 1;
		while (count <= 99)
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

void	ft_print_comb2(void)
{
	int c;
	int	answer[3];
	int	visited[100];

	c = 0;
	answer[0] = -1;
	while (c <= 99)
	{
		visited[c] = 0;
		c++;
	}
	dfs(1, answer, visited);
}
