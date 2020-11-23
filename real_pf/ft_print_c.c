/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:00:29 by ukim              #+#    #+#             */
/*   Updated: 2020/11/23 17:07:55 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	width_zero(char c)
{
	write(1, &c, 1);
	return (1);
}

int			ft_print_c(t_flags *flag, va_list ap)
{
	char		c;
	int		i;

	i = 0;
	c = va_arg(ap, int);
	if (flag->width <= 0)
		return (width_zero(c));
	if (!flag->minus)
	{
		while (i++ < flag->width - 1)
			write(1, " ", 1);
		write(1, &c, 1);
	}
	else
	{
		write(1, &c, 1);
		while (i++ < flag->width - 1)
			write(1, " ", 1);
	}
	return (flag->width);
}