/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:33:53 by ukim              #+#    #+#             */
/*   Updated: 2020/11/28 12:25:35 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					g_len = 0;
char				*g_base_10 = "0123456789";
char				*g_base_x = "0123456789abcdef";
char				*g_base_xx = "0123456789ABCDEF";

char				is_option(char *fm)
{
	if (*fm == 'c' || *fm == 's' || *fm == 'i'
			|| *fm == 'd' || *fm == 'u' || *fm == 'x'
			|| *fm == 'X' || *fm == 'p' || *fm == '%')
		return (*fm);
	return (0);
}

static int			do_op(t_flags *flag, char *fm, va_list ap)
{
	char			c;

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
		g_len += ft_print_ux(flag, ap, g_base_xx);
	else if (c == 'p')
		g_len += ft_print_point(flag, ap);
	else if (c == 's')
		g_len += ft_print_str(flag, ap);
	else if (c == '%')
		g_len += ft_print_percent(flag);
	return (0);
}

int					ft_printf(const char *format, ...)
{
	char			*save;
	t_flags			flag;
	va_list			ap;

	g_len = 0;
	va_start(ap, format);
	save = (char *)format;
	while (*save)
	{
		if (*save == '%')
		{
			save++;
			init_flag(&flag);
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
/*
** int main()
** {
** 	int a = -135;
** 	ft_printf("Hello World %-*.*d$\n",4,4,a);
** 	printf("Hello World %-*.*d$\n",4,4,a);
**
** 	ft_printf("Hello World %-4.4d$\n",a);
** 	printf("Hello World %-4.4d$\n",a);
** 	a = -12;
** 	ft_printf("Hello World %0*.d$\n",4,a);
** 	printf("Hello World %0*.d$\n",4,a);
**
** 	ft_printf("Hello World %0*.0d$\n",4,a);
** 	printf("Hello World %0*.*d$\n",4,0,a);
** 	ft_printf("Hello World %0*.4d$\n",4,a);
** 	printf("Hello World %0*.4d$\n",4,a);
** 	ft_printf("Hello World %0*.*d$\n",4,-3,a);
** 	printf("Hello World %0*.*d$\n",4,-3,a);
** 	a = -2147483648;
** 	ft_printf("Hello World %d$\n",a);
** 	printf("Hello World %d$\n",a);
** }
*/
