/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:24:19 by ukim              #+#    #+#             */
/*   Updated: 2020/11/12 20:24:05 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		change_star(t_flags *flag, va_list ap)
{
	int tmp;

	if (flag->star == 2)
	{
		if ((tmp = va_arg(ap, int)) < 0)
		{
			flag->minus = 1;
			tmp *= -1;
		}
		flag->width = tmp;
		if ((tmp = va_arg(ap, int)) < 0)
			tmp *= -1;
		flag->precision = tmp;
	}
	else if (flag->star == 1 && flag->dot == 1)
	{
		if ((tmp = va_arg(ap, int)) < 0)
			tmp *= -1;
		flag->precision = tmp;
	}
	else if (flag->star == 1 && flag->dot != 1)
	{
		if ((tmp = va_arg(ap, int)) < 0)
		{
			flag->minus = 1;
			tmp *= -1;
		}
		flag->width = tmp;
	}
}
