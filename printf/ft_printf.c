/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:35:44 by ukim              #+#    #+#             */
/*   Updated: 2020/11/11 21:53:32 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_flag(t_flags *tf)
{
	tf->minus = 0;
	tf->precision = -1;
	tf->width = -1;
	tf->zero = 0;
	tf->star = 0;
	tf->dot = 0;
}

char			is_option(char *fm)
{
	if (*fm == 'c' || *fm == 's'|| *fm == 'i'
	 || *fm == 'd' || *fm == 'u' || *fm == 'x'
	 || *fm == 'X' || *fm == 'p' || *fm == '%')
		return (*fm);
	return (0);
}

char			what_flag(t_flags *fg, char *fm)
{
	if (is_option(fm))
		return (0);
	if (*fm == '-')
	{
		fg->minus = 1;
		return ('-');
	}
	else if (*fm == '0')
	{
		fg->zero = 1;
		return ('0');
	}
	else if (*fm == '*')
	{
		fg->star++;
		return ('*');
	}
	else if (*fm == '.')
	{
		fg->dot = 1;
		return ('.');
	}
	else if (*fm <= '9' && *fm >= '0')
		return (1);
	return (0);
}

void			set_flag(t_flags *fg ,char **fm)
{
	char	c;
	int		wf;
	int		pf;

	c = 1;
	wf = 1;
	pf = 0;
	while ((c = what_flag(fg, *fm)))
	{
		if (c == '.')
		{
			wf = 0;
			pf = 1;
		}
		if (c == 1 && wf == 1 && pf != 1)
		{
			fg->width = ft_atoi(fm);
			wf = 0;
			continue;
		}
		else if (c == 1 && wf == 0 && pf == 1)
		{
			fg->precision = ft_atoi(fm); // 여기서 나올 떄는 마지막 숫자를 가르키고 있어야함.
			continue;
		}
		(*fm)++;
	}
}

int				do_op(t_flags *flag, char *fm, va_list ap)
{
	char	c;
	int		count;

	if (!(c = is_option(fm)))
		return (0);
	if (c == 'c')
		ft_print_c(flag, ap);
    /*
    else if (c == 's')
        ft_print_str(flag, ap);
    else if (c == 'd' || c == 'i')
        ft_print_digit(flag, ap);
    else if (c == 'u')
        ft_print_ui(flag, ap);
    else if (c == 'p')
        ft_print_point(flag, ap);
    else if (c == 'x')
        ft_print_octo(flag, ap);
    else if (c == 'X')
        ft_print_Cocto(flag, ap);
    */
	return (0);
}

int				ft_printf(const char *format, ...)
{
	char	*save;
	int		len;
	t_flags flag;
	va_list ap;

	va_start(ap, format);
	save = (char *)format;
	len = 0;
	while (*save)
	{
		if (*save == '%')
		{
			save++;
			init_flag(&flag);
			set_flag(&flag, &save);
			do_op(&flag, save, ap);
		}
		else
			write(1, save, 1);
		save++;
	}
	va_end(ap);
	return (len);
}

int			main()
{
	ft_printf("print this : %c\n", 97);
}
