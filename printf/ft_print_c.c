/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:00:29 by ukim              #+#    #+#             */
/*   Updated: 2020/11/11 23:02:59 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_c(t_flags *flag, va_list ap)
{
	char 	c;
	char 	*str;
	int		i;

	i = 0;
	change_star(flag, ap);
	if (flag->width < 0)
	{
		flag->minus = 1;
		flag->width *= -1;
	}
	str = (char*)malloc(sizeof(char) * flag->width + 1);
	while (i < flag->width)
		str[i++] = ' ';
	c = va_arg(ap, int);
	if (flag->minus == 1)
		str[0] = c;
	else
		str[flag->width - 1] = c;
	str[flag->width] = 0;
	write(1, str, flag->width);
	return (flag->width);
}
