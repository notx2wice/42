/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 19:41:09 by ukim              #+#    #+#             */
/*   Updated: 2021/01/14 20:31:02 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atoi(char *str, int *idx)
{
	unsigned long long	num;
	int					sign;
	int					j;

	if (!str || !*str)
		return (0);
	num = 0;
	sign = 1;
	j = 0;
	while (!ft_isdigit(str[j]))
		j++;
	while (str[j] && ft_isdigit(str[j]))
	{
		num *= 10;
		num += str[j] - '0';
		j++;
	}
	if (idx)
		*(idx) += j + 1;
	return (sign * num);
}
