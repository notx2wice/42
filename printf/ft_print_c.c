/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:00:29 by ukim              #+#    #+#             */
/*   Updated: 2020/11/12 16:57:59 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	width_zero(char **str)
{
	*str = (char*)malloc(sizeof(char) * 2);
	write(1, *str, 1);
	free(*str);
	return (1);
}

int			ft_print_c(t_flags *flag, va_list ap)
{
	char	c;
	char	*str;
	int		i;

	i = 0;
	change_star(flag, ap);
	if (flag->width <= 0)
		return (width_zero(&str));
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
	free(str);
	return (flag->width);
}
