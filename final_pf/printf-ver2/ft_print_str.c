/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:23:18 by ukim              #+#    #+#             */
/*   Updated: 2020/11/28 11:38:27 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*make_trim(char *str, int length)
{
	char			*trim;
	int				i;

	if (!(trim = (char *)malloc(sizeof(char) * (length + 1))))
		return (0);
	i = 0;
	while (length--)
		trim[i++] = *str++;
	trim[i] = '\0';
	return (trim);
}

int					str_print_minus(t_flags *flag, char *str, char c)
{
	char			*result;
	int				len;

	if (flag->minus == 0)
		result = ft_left_strcat(str, c, (flag->width - ft_strlen(str)));
	else
		result = ft_right_strcat(str, c, (flag->width - ft_strlen(str)));
	ft_putstr(result);
	len = ft_strlen(result);
	free(result);
	return (len);
}

static int			str_precision_width_flag(t_flags *flag, char *str)
{
	int				len;
	int				t_len;
	int				m_precision;
	char			*trim;

	len = ft_strlen(str);
	if ((m_precision = flag->precision) < 0)
		m_precision *= (-1);
	if (m_precision < len)
	{
		trim = make_trim(str, m_precision);
		if (flag->width <= (t_len = ft_strlen(trim)))
		{
			ft_putstr(trim);
			free(trim);
			return (t_len);
		}
		t_len = str_print_minus(flag, trim, ' ');
		free(trim);
		return (t_len);
	}
	else if (flag->width > len)
		return (str_print_minus(flag, str, ' '));
	ft_putstr(str);
	return (ft_strlen(str));
}

static int			str_width_flag(t_flags *flag, char *str)
{
	int				len;
	char			*result;

	len = ft_strlen(str);
	if (flag->width)
	{
		if (flag->width > len)
		{
			if (flag->zero == 0)
				return (str_print_minus(flag, str, ' '));
			else
			{
				if (flag->minus == 0)
					result = ft_left_strcat(str, '0', (flag->width - len));
				else
					result = ft_right_strcat(str, ' ', (flag->width - len));
			}
			ft_putstr(result);
			len = ft_strlen(result);
			free(result);
			return (len);
		}
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

int					ft_print_str(t_flags *flag, va_list ap)
{
	char			*str;
	int				count;

	if (!(str = (char *)va_arg(ap, void *)))
		str = "(null)";
	if (flag->pf == 0)
		count = str_width_flag(flag, str);
	else
		count = str_precision_width_flag(flag, str);
	return (count);
}
