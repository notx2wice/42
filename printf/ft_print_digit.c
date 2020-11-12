/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:25:07 by ukim              #+#    #+#             */
/*   Updated: 2020/11/12 17:19:30 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// int-len > precision > width
// precision이 붙은 순간 부터 -flag 무시
// 프리시전은 수에 붙은 - 제외한 공간의 크기이다.
// width는 -포함 길이
int		ft_print_digit(t_flags *flag, va_list ap)
{
	int		slen;
	int		para_int;
	char	*istr;

	
	change_star(flag, ap);
	para_int = va_arg(ap, int);
	istr = ft_itoa(para_int);
	slen = ft_strlen(istr);
	write(1, istr, slen);
	return (slen);
}
