/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 20:29:51 by ukim              #+#    #+#             */
/*   Updated: 2020/08/10 20:41:57 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	get_ox(int n)
{
	if (n < 10)
		return (n + '0');
	else
		return (n + 'a' - 10);
}

void	print_ox(unsigned char c)
{
	unsigned char a;

	write(1, "\\", 1);
	a = get_ox(c / 16 % 16);
	write(1, &a, 1);
	a = get_ox(c % 16);
	write(1, &a, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	x;

	x = -1;
	while (str[++x])
	{
		if (str[x] >= 32 && str[x] <= 126)
			write(1, &str[x], 1);
		else
			print_ox(str[x]);
	}
}
