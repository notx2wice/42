/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:35:44 by ukim              #+#    #+#             */
/*   Updated: 2020/11/15 17:25:03 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*g_base_10 = "0123456789";
char			*g_base_x = "0123456789abcdef";
char			*g_base_X = "0123456789ABCDEF";

static void		init_flag(t_flags *tf)
{
	tf->minus = 0;
	tf->precision = 0;
	tf->width = 0;
	tf->zero = 0;
	tf->star = 0;
	tf->dot = 0;
	tf->wf = 0;
	tf->pf = 0;
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
			fg->wf = 1;
			wf = 0;
			continue;
		}
		else if (c == 1 && wf == 0 && pf == 1)
		{
			fg->precision = ft_atoi(fm);
			fg->pf = 1;
			continue;
		}
		(*fm)++;
	}
}

int				do_op(t_flags *flag, char *fm, va_list ap)
{
	char	c;

	if (!(c = is_option(fm)))
		return (0);
	if (c == 'c')
		ft_print_c(flag, ap);
	else if (c == 'd' || c == 'i')
		ft_print_digit(flag, ap);
	else if (c == 'u')
		ft_print_ux(flag, ap, 'u');
	else if (c == 'x')
		ft_print_ux(flag, ap, 'x');
	else if (c == 'X')
		ft_print_ux(flag, ap, 'X');
	/*
	else if (c == 'p')
		ft_print_point(flag, ap);
	else if (c == 's')
		ft_print_str(flag, ap);
	*/
	return (0);
}
void			zero_minus(t_flags *fg, char **sv)
{
	if (**sv == '-')
	{
		fg->minus = 1;
		(*sv)++;
	}
	else if (**sv == '0')
	{
		fg->zero = 1;
		(*sv)++;
	}
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
			zero_minus(&flag, &save);
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
	ft_printf("print_this:%*.0d$\n",12,-12345);
	printf("print_this:%*.0d$\n",12,-12345);
	ft_printf("print_this:%*.0d$\n",-12,-12345);
	printf("print_this:%*.0d$\n",-12,-12345);
	ft_printf("print_this:%*.*d$\n",16,13,-12345);
	printf("print_this:%*.*d$\n",16,13,-12345);

}
