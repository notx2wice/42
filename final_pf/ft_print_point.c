/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:13:00 by ukim              #+#    #+#             */
/*   Updated: 2020/11/28 16:57:03 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*change_to_char_base(unsigned long long pointer, \
		int base, int count)
{
	char				*hexa;
	unsigned long long	ull;

	ull = pointer;
	if (!(hexa = (char *)malloc(sizeof(char) * (count + 1))))
		return (0);
	hexa[count--] = '\0';
	while (ull > 0)
	{
		hexa[count--] = g_base_x[ull % base];
		ull /= base;
	}
	return (hexa);
}

static char				*point_precision_width_flag(t_flags *flag, \
		char *conv_point)
{
	int					len;
	char				*tmp[2];
	char				*result;
	char				*prefix;

	prefix = ft_strdup("0x");
	len = flag->precision - ft_strlen(conv_point);
	if (flag->pf == 1 && len > 0)
	{
		tmp[0] = init_c_malloc('0', len);
		tmp[1] = ft_free_strjoin(tmp[0], conv_point);
		result = ft_free_strjoin(prefix, tmp[1]);
	}
	else
		result = ft_free_strjoin(prefix, conv_point);
	if ((len = flag->width - ft_strlen(result)) > 0)
	{
		tmp[0] = init_c_malloc(' ', len);
		if (flag->minus == 0)
			tmp[1] = ft_free_strjoin(tmp[0], result);
		else
			tmp[1] = ft_free_strjoin(result, tmp[0]);
		return (tmp[1]);
	}
	return (result);
}

char					*change_to_char_null(t_flags *flag)
{
	int					len;
	char				*tmp[2];
	char				*prefix;
	char				*result;

	if (flag->dot == 1)
	{
		len = flag->precision < 0 ? 1 : flag->precision;
		prefix = ft_strdup("0x");
		tmp[0] = init_c_malloc('0', len);
		tmp[1] = ft_free_strjoin(prefix, tmp[0]);
	}
	else
		tmp[1] = ft_strdup("0x0");
	len = flag->width - ft_strlen(tmp[1]);
	if (len > 0)
	{
		tmp[0] = init_c_malloc(' ', len);
		if (flag->minus == 0)
			result = ft_free_strjoin(tmp[0], tmp[1]);
		else
			result = ft_free_strjoin(tmp[1], tmp[0]);
		return (result);
	}
	return (tmp[1]);
}

int						ft_print_point(t_flags *flag, va_list ap)
{
	char				*result;
	unsigned long long	pointer;
	int					count;
	char				*conv_point;

	pointer = va_arg(ap, unsigned long long);
	count = ull_length(pointer, 16);
	if (pointer)
	{
		conv_point = change_to_char_base(pointer, 16, count);
		result = point_precision_width_flag(flag, conv_point);
	}
	else
		result = change_to_char_null(flag);
	ft_putstr(result);
	count = ft_strlen(result);
	free(result);
	return (count);
}
