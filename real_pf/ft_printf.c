/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:35:44 by ukim              #+#    #+#             */
/*   Updated: 2020/11/18 18:59:51 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				g_len = 0;
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

static char			is_option(char *fm)
{
	if (*fm == 'c' || *fm == 's'|| *fm == 'i'
	 || *fm == 'd' || *fm == 'u' || *fm == 'x'
	 || *fm == 'X' || *fm == 'p' || *fm == '%')
		return (*fm);
	return (0);
}

static char			what_flag(t_flags *fg, char *fm, va_list ap)
{
	int			star;

	if (is_option(fm))
		return (0);
	else if (*fm == '*')
	{
		star = va_arg(ap, int);
		if (fg->dot == 1)
		{
			if (star < 0)
			{
				fg->pf = 0;
				fg->precision = star;
				return (10);
			}
			fg->precision = star;
			fg->pf = 1;
		}
		else
		{
			if (star < 0)
			{
				fg->minus = 1;
				star *= -1;
			}
			fg->width = star;
			fg->wf = 1;
		}
		return ('*');
	}
	else if (*fm == '.')
	{
		fg->dot = 1;
		return ('.');
	}
	else if ((*fm <= '9' && *fm >= '0') || *fm == '-')
		return (1);
	return (10);
}

static void			set_flag(t_flags *fg ,char **fm, va_list ap)
{
	char	c;
	int		wf;
	int		pf;

	c = 1;
	wf = 1;
	pf = 0;
	while ((c = what_flag(fg, *fm, ap)))
	{
		if (c == '.')
		{
			fg->wf = 0;
			fg->pf = 1;
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
			if (fg->precision < 0)
				fg->pf = 0;
			continue;
		}
		(*fm)++;
	}
}

static int				do_op(t_flags *flag, char *fm, va_list ap)
{
	char	c;

	if (!(c = is_option(fm)))
		return (0);
	if (c == 'c')
		g_len += ft_print_c(flag, ap);
	else if (c == 'd' || c == 'i')
		g_len += ft_print_digit(flag, ap);
	else if (c == 'u')
		g_len += ft_print_ux(flag, ap, g_base_10);
	else if (c == 'x')
		g_len += ft_print_ux(flag, ap, g_base_x);
	else if (c == 'X')
		g_len += ft_print_ux(flag, ap, g_base_X);
	else if (c == 'p')
		g_len += ft_print_point(flag, ap);
	else if (c == 's')
		g_len += ft_print_str(flag, ap);
	return (0);
}

static void			zero_minus(t_flags *fg, char **sv)
{
	while (**sv == '-' || **sv == '0')
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
}

int				ft_printf(const char *format, ...)
{
	char	*save;
	t_flags flag;
	va_list ap;

	g_len = 0;
	va_start(ap, format);
	save = (char *)format;
	while (*save)
	{
		if (*save == '%')
		{
			save++;
			if (*save == '%')
			{
				write(1, "%", 1);
				save++;
				g_len++;
				continue;
			}
			init_flag(&flag);
			zero_minus(&flag, &save);
			set_flag(&flag, &save, ap);
			do_op(&flag, save, ap);
		}
		else
		{
			write(1, save, 1);
			g_len++;
		}
		save++;
	}
	va_end(ap);
	return (g_len);
}

int			main()
{
	char	*str;
	str = "haha";
	int d = -12;
	ft_printf("print_this:%-*.*x$\n", 3, -4, 0);
	printf("print_this:%-*.*x$\n", 3, -4, 0);
	ft_printf("print_this:%--*.0x$\n",-12,-12345);
	printf("print_this:%--*.0x$\n",-12,-12345);
	ft_printf("print_this:%--*.*X$\n",16,13,-12345);
	printf("print_this:%--*.*X$\n",16,13,-12345);
	ft_printf("print_this:%-4.1X$\n", -12345);
	printf("print_this:%-4.1X$\n", -12345);
	ft_printf("print_this:%0*.*x$\n", 6, -4, 123);
	printf("print_this:%0*.*x$\n", 6, -4, 123);
	ft_printf("print_this:%*.*s$\n", -20, -10, "competition");
	printf("print_this:%*.*s$\n", -20, -10, "competition");
	ft_printf("print_this:%*p$\n", 20, str);
	printf("print_this:%*p$\n", 20, str);
	ft_printf("print_this:%*.*d$\n", -10, 5, 382727);
	printf("print_this:%*.*d$\n", -10, 5, 382727);
	ft_printf("print_this:%*.*u$\n", -10, 5, 38273489);
	printf("print_this:%*.*u$\n", -10, 5, 38273489);

	ft_printf("print_this:%04d$\n",d);
	printf("print_this:%04d$\n",d);


	ft_printf("print_this:%0*.*d$\n", 4,-4,d);
  	printf("print_this:%0*.*d$\n", 4,-4,d);
	ft_printf("print_this:%0*.d$\n", 4,d);
  	printf("print_this:%0*.d$\n", 4,d);
	d = 0;
	ft_printf("print_this:%-4.d$\n", d);
	printf("print_this:%-4.d$\n", d);
	ft_printf("print_this:%-4.*d$\n",-3, d);
	printf("print_this:%-4.*d$\n",-3, d);

	ft_printf("print_this:%-4d$\n", d);
	printf("print_this:%-4d$\n", d);

	ft_printf("print_this:%-4.x$\n", d);
	printf("print_this:%-4.x$\n", d);

}
