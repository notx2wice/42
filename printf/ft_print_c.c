/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:00:29 by ukim              #+#    #+#             */
/*   Updated: 2020/11/11 21:45:47 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	change_star(t_flags *flag, va_list ap)
{//0 , precision 무시 , 그러나 -, width,는 신경 써야함
	if (flag->star == 2)
	{

	}
	else if (flag->star == 1 && flag->dot == 1)
	{

	}
	else if (flag->star == 1 && flag->dot != 1)
	{

	}
}

int		ft_print_c(t_flags *flag, va_list ap)
{
	char c;

	change_star(flag, ap);
	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}
