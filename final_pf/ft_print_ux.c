/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:12:27 by ukim              #+#    #+#             */
/*   Updated: 2020/11/28 16:39:54 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*change_base_to_string(unsigned long long num, char *base)
{
	int				len;
	char			*str;
	int				base_len;

	base_len = ft_strlen(base);
	len = ull_length(num, base_len);
	if (num == 0)
		return (ft_strdup("0"));
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len--] = '\0';
	while (num > 0)
	{
		str[len--] = base[num % base_len];
		num /= base_len;
	}
	return (str);
}

static void			ux_width_flag(t_flags *flag, int t_len, char **str)
{
	char			c;
	char			*tmp[2];

	if (t_len > 0)
	{
		if (flag->minus)
		{
			tmp[0] = *str;
			tmp[1] = init_c_malloc(' ', t_len);
		}
		else
		{
			c = flag->zero && flag->pf == 0 ? '0' : ' ';
			tmp[0] = init_c_malloc(c, t_len);
			tmp[1] = *str;
		}
		*str = ft_free_strjoin(tmp[0], tmp[1]);
	}
}

int					ft_print_ux(t_flags *flag, va_list ap, char *base)
{
	int				t_len;
	unsigned int	num;
	char			*str;
	char			*tmp[2];

	num = va_arg(ap, unsigned int);
	str = change_base_to_string(num, base);
	if (num == 0 && flag->precision == 0 && flag->dot == 1)
	{
		free(str);
		str = ft_strdup("");
	}
	t_len = flag->precision - ft_strlen(str);
	if (t_len > 0)
	{
		tmp[0] = init_c_malloc('0', t_len);
		str = ft_free_strjoin(tmp[0], str);
	}
	ux_width_flag(flag, (flag->width - ft_strlen(str)), &str);
	ft_putstr(str);
	t_len = ft_strlen(str);
	free(str);
	return (t_len);
}
