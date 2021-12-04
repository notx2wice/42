/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:56:14 by ukim              #+#    #+#             */
/*   Updated: 2020/11/28 11:35:05 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_power(long n)
{
	int			length;

	length = 0;
	while (n / 10 > 0)
	{
		length++;
		n /= 10;
	}
	return (length + 1);
}

char			*ft_itoa(long long n)
{
	char		*result;
	int			minus;
	int			len;
	long long	nb;

	nb = n;
	minus = 0;
	if (nb < 0)
	{
		minus = 1;
		nb *= -1;
	}
	len = get_power(nb) + minus;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (minus == 1)
		result[0] = '-';
	result[len--] = '\0';
	while (nb > 0 || len >= minus)
	{
		result[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (result);
}
