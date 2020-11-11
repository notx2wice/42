/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:24:19 by ukim              #+#    #+#             */
/*   Updated: 2020/11/11 21:59:39 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isdigit(char *str)
{
	if (*str >= '0' && *str <= '9')
		return (1);
	return (0);
}

int			ft_atoi(char **str)
{
	unsigned long long	num;
	int					sign;

	num = 0;
	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	while (**str && ft_isdigit(*str))
	{
		num *= 10;
		num += **str - '0';
		(*str)++;
	}
	return (sign * num);
}

void		change_star(t_flags *flag, va_list ap)
{
	int tmp;

	if (flag->star == 2)
	{
		tmp = va_arg(ap, int);
		flag->width = tmp;
		tmp = va_arg(ap, int);
		flag->precision = tmp;
	}
	else if (flag->star == 1 && flag->dot == 1)
	{
		tmp = va_arg(ap, int);
		flag->precision = tmp;
	}
	else if (flag->star == 1 && flag->dot != 1)
	{
		tmp = va_arg(ap, int);
		flag->width = tmp;
	}
}
