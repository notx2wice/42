/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-eunju <kim-eunju@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 19:41:09 by ukim              #+#    #+#             */
/*   Updated: 2021/01/07 21:56:05 by kim-eunju        ###   ########.fr       */
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
	if (str[j] == ' ' || str[j] == ',' || ft_isalpha(str[j]))
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
