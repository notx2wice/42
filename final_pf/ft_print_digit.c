/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:13:36 by ukim              #+#    #+#             */
/*   Updated: 2020/11/28 11:48:29 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_free_strjoin(char *s1, char *s2)
{
	char		*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (str);
}

static void		add_space(char **istr, t_flags *fg)
{
	int			x;

	x = fg->width - ft_strlen(*istr);
	if (x > 0)
	{
		if (fg->minus)
			*istr = ft_free_strjoin(*istr, init_c_malloc(' ', x));
		else
			*istr = ft_free_strjoin(init_c_malloc(' ', x), *istr);
	}
}

void			add_zero(char **istr, int minus, t_flags *fg)
{
	int			nlen;
	int			x;

	nlen = ft_strlen(*istr);
	if (fg->precision > 0)
	{
		x = fg->precision - nlen;
		if (x >= 0)
			*istr = ft_free_strjoin(init_c_malloc('0', x), *istr);
	}
	else
	{
		x = fg->width - nlen;
		if (!fg->minus && fg->zero && x > 0 && fg->pf == 0)
			*istr = ft_free_strjoin(init_c_malloc('0', x + minus), *istr);
	}
}

static char		*int_to_istr(t_flags *flag, va_list ap)
{
	char		*istr;
	char		*mstr;
	int			mf;
	long long	para_int;

	mf = 0;
	if ((para_int = va_arg(ap, int)) < 0)
	{
		mf = -1;
		para_int *= -1;
	}
	istr = ft_itoa(para_int);
	if (para_int == 0 && flag->precision == 0 && flag->dot == 1)
	{
		free(istr);
		istr = ft_strdup("");
	}
	add_zero(&istr, mf, flag);
	if (mf == -1)
	{
		mstr = ft_strdup("-");
		istr = ft_free_strjoin(mstr, istr);
	}
	add_space(&istr, flag);
	return (istr);
}

int				ft_print_digit(t_flags *flag, va_list ap)
{
	int			slen;
	char		*istr;

	istr = int_to_istr(flag, ap);
	ft_putstr(istr);
	slen = ft_strlen(istr);
	free(istr);
	return (slen);
}
