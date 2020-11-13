/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:37:50 by ukim              #+#    #+#             */
/*   Updated: 2020/11/13 19:31:37 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef struct s_flags
{
    int minus;
    int zero;
    int star;
    int width;
    int precision;
    int dot;
	int wf;
	int pf;
}               t_flags;

int			ft_print_c(t_flags *flag, va_list ap);
int	        ft_print_digit(t_flags *flag, va_list ap);
int			ft_print_str(t_flags *flag, va_list ap);
void		change_star(t_flags *flag, va_list ap);
void		add_zero(char **istr, int minus, t_flags *fg);
char		*ft_free_strjoin(char *s1, char *s2);
char		*init_c_malloc(char c, int i);

#endif