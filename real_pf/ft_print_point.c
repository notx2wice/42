/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:25:13 by ukim              #+#    #+#             */
/*   Updated: 2020/11/23 17:11:13 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*change_to_char_base(unsigned long long pointer, int base, int count)
{
   char					*hexa;
   char					*prefix;
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
	prefix = ft_strdup("0x");
	return (ft_free_strjoin(prefix, hexa));
}

static int				point_width_flag(t_flags *flag, char *conv_point)
{
   int					length;

	if ((length = flag->width - ft_strlen(conv_point)) > 0)
		return (str_print_minus(flag, conv_point));
	else
		ft_putstr(conv_point);
	return (ft_strlen(conv_point));
}

int						ft_print_point(t_flags *flag, va_list ap)
{
	int					count;
	void					*tmp;
	unsigned long long	pointer;
	char					*conv_point;

	tmp = (void *)va_arg(ap, void *);
	if (tmp == NULL)
		conv_point = ft_strdup("0x0");
	else
	{
		pointer = (unsigned long long)tmp;
		count = ull_length(pointer, 16);
		conv_point = change_to_char_base(pointer, 16, count);
	}
	count = point_width_flag(flag, conv_point);
	free(conv_point);
	return (count);
}