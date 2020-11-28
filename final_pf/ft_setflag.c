/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:28:47 by ukim              #+#    #+#             */
/*   Updated: 2020/11/28 11:39:06 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_flag(t_flags *fg)
{
	fg->minus = 0;
	fg->precision = 0;
	fg->width = 0;
	fg->zero = 0;
	fg->dot = 0;
	fg->wf = 0;
	fg->pf = 0;
}

static void		zero_minus(t_flags *fg, char **fm)
{
	while (**fm == '-' || **fm == '0')
	{
		if (**fm == '-')
		{
			fg->minus = 1;
			(*fm)++;
		}
		else if (**fm == '0')
		{
			fg->zero = 1;
			(*fm)++;
		}
	}
}

static char		set_star_as_flag(t_flags *fg, int star)
{
	if (fg->dot == 1)
	{
		if (star < 0)
		{
			fg->pf = 0;
			fg->precision = star;
			return (0);
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
	return (0);
}

static char		what_flag(t_flags *fg, char *fm, va_list ap)
{
	int			star;

	if (*fm == '*')
	{
		star = va_arg(ap, int);
		return (set_star_as_flag(fg, star));
	}
	else if (*fm == '.')
	{
		fg->dot = 1;
		fg->pf = 1;
		return (0);
	}
	else if ((*fm <= '9' && *fm >= '0') || *fm == '-')
		return (1);
	return (0);
}

void			set_flag(t_flags *fg, char **fm, va_list ap)
{
	zero_minus(fg, fm);
	while (!is_option(*fm))
	{
		if (what_flag(fg, *fm, ap))
		{
			if (fg->dot == 0 && fg->wf == 0)
			{
				fg->width = ft_atoi(fm);
				fg->wf = 1;
				continue;
			}
			else if (fg->dot == 1)
			{
				fg->precision = ft_atoi(fm);
				if (fg->precision < 0)
					fg->pf = 0;
				else
					fg->pf = 1;
				continue;
			}
		}
		(*fm)++;
	}
}
