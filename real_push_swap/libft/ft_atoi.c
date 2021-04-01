/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 19:41:09 by ukim              #+#    #+#             */
/*   Updated: 2021/03/31 18:03:55 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	is_space(int c)
{
	if (c == ' ' ||
		c == '\n' ||
		c == '\t' ||
		c == '\v' ||
		c == '\f' ||
		c == '\r')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned long long	num;
	int					sign;

	num = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (num > LLONG_MAX)
		return (sign == 1 ? -1 : 0);
	return (sign * num);
}

void		make_sign(int *sign, const char **str)
{
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign *= -1;
		(*str)++;
	}
}

int			pw_atoi(const char *str, int *flag)
{
	unsigned long long	num;
	int					sign;

	num = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	make_sign(&sign, &str);
	while (*str && ft_isdigit(*str))
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (num > LLONG_MAX)
		return (sign == 1 ? -1 : 0);
	if (num >= 2147483649ull || (*str && !ft_isdigit(*str)))
		*flag = 0;
	if ((num == 2147483648ull && sign == 1) \
		|| (num == 2147483647 && sign == -1))
		*flag = 0;
	return (sign * num);
}
