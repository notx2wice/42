/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:07:50 by ukim              #+#    #+#             */
/*   Updated: 2020/11/24 17:26:35 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     	ft_print_percent(t_flags *flag)
{
	char	*result;
	if (flag->width > 1)
	{
		if (flag->zero == 1)
		{
			if (flag->minus == 0)
				result = ft_left_strcat("%", '0', flag->width -1);
			else
				result = ft_right_strcat("%", ' ', flag->width - 1);
		}
		else
		{
			if (flag->minus == 0)
				result = ft_left_strcat("%", ' ', flag->width - 1);
			else
				result = ft_right_strcat("%", ' ', flag->width - 1);
		}
		ft_putstr(result);
		free(result);
		return (flag->width);
	}
	ft_putstr("%");
	return (1);
}
