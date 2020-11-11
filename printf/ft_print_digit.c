/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:25:07 by ukim              #+#    #+#             */
/*   Updated: 2020/11/11 23:26:42 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// int-len > precision > width
// precision이 붙은 순간 부터 -flag 무시
// 프리시전은 수에 붙은 - 제외한 공간의 크기이다.
// width는 -포함 길이
int		ft_print_digit(t_flags *flag, va_list ap)
{
	int		t_int;
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
	t_int = va_arg(ap, int);
	if (flag->minus == 1)
		str[0] = c;
	else
		str[flag->width - 1] = c;
	str[flag->width] = 0;
	write(1, str, flag->width);
	return (flag->width);
}
