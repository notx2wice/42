/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 13:50:09 by ukim              #+#    #+#             */
/*   Updated: 2020/08/08 13:50:24 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		comp_str(char *s1, char *s2)
{
	int x;

	x = 0;
	while (s1[x] && s2[x])
	{
		if (s1[x] > s2[x])
			return (1);
		if (s2[x] > s1[x])
			return (-1);
		x++;
	}
	if (!s1[x] && !s2[x])
		return (0);
	if (s1[x])
		return (1);
	return (-1);
}

void	print(int argc, char *argv[])
{
	int x;
	int y;

	x = 1;
	while (x < argc)
	{
		y = 0;
		while (argv[x][y])
		{
			write(1, &argv[x][y], 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}
}

int		main(int argc, char *argv[])
{
	int		x;
	int		y;
	char	*temp;

	x = 1;
	while (x < argc)
	{
		y = x + 1;
		while (y < argc)
		{
			if (comp_str(argc[x], argv[y]) > 0)
			{
				temp = argv[x];
				argv[x] = argv[y];
				argv[y] = temp;
			}
			y++;
		}
		x++;
	}
	print(argc, argv);
}
