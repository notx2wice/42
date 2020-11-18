/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekim <ekim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:25:13 by ukim              #+#    #+#             */
/*   Updated: 2020/11/17 21:17:54 by ekim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char					*change_to_char_base(unsigned long long pointer, int base, int count)
{
	char				*alpha;
	char    			*result;
	unsigned long long	ull;

    ull = pointer;
	alpha = "0123456789abcdef";
    if (!(result = (char *)malloc(sizeof(char) * (count + 1))))
		return (0);
	result[count--] = '\0';
	result[0] = '0';
	result[1] = 'x';
	while (ull > 0 && count > 1)
	{
		result[count--] = alpha[ull % base];
		ull /= base;
	}
	return (result);
}

static int						point_width_flag(t_flags *flag, char *conv_point)
{
	char				*result;
	int					length;

	if ((length = flag->width - ft_strlen(conv_point)) > 0)
	{
		if (flag->minus == 0)
			result = ft_left_strcat(conv_point, ' ', length);
		else
			result = ft_right_strcat(conv_point, ' ', length);
		ft_putstr(result);
		return (ft_strlen(result));
	}
	ft_putstr(conv_point);
	return (ft_strlen(conv_point));
}

int						ft_print_point(t_flags *flag, va_list ap)
{
	int					count;
	void				*tmp;
	unsigned long long	pointer;
	char				*conv_point;

	tmp = (void *)va_arg(ap, void *);
	if (tmp == NULL)
		conv_point = ft_strdup("(nil)");
	else
	{
		pointer = (unsigned long long)tmp;
		count = ull_length(pointer, 16);
		conv_point = change_to_char_base(pointer, 16, count + 2);
	}
	count = point_width_flag(flag, conv_point);
	free(conv_point);
	return (count);
}