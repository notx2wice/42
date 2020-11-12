/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:24:19 by ukim              #+#    #+#             */
/*   Updated: 2020/11/12 17:54:44 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		change_star(t_flags *flag, va_list ap)
{
	int tmp;

	if (flag->star == 2)
	{
		tmp = va_arg(ap, int);
		if (tmp < 0)
		{
			flag->minus = 1;
			flag->width = -tmp;
		}
		else
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
		if (tmp < 0)
		{
			flag->minus = 1;
			flag->width = -tmp;
		}
		else
			flag->width = tmp;
	}
}
