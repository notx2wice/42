/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 19:43:15 by ukim              #+#    #+#             */
/*   Updated: 2020/08/05 12:20:55 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	int_printer(long a)
{
	char t;

	t = a + 48;
	write(1, &t, 1);
}

void	dfs(long ab)
{
	int a;
	int b;

	a = ab / 10;
	b = ab % 10;
	if (ab == 0)
	{
		return ;
	}
	else
	{
		dfs(a);
		int_printer(b);
	}
}

void	ft_putnbr(int aab)
{
	char	minus;
	long	ab;

	ab = aab;
	minus = '-';
	if (ab == 0)
		int_printer(0);
	else if (ab > 0)
		dfs(ab);
	else
	{
		write(1, &minus, 1);
		dfs(-1 * ab);
	}
}
