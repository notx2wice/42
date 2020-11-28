/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:26:59 by ukim              #+#    #+#             */
/*   Updated: 2020/11/28 11:34:54 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atoi(char **str)
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
	while (**str && ft_isdigit(**str))
	{
		num *= 10;
		num += **str - '0';
		(*str)++;
	}
	return (sign * num);
}
