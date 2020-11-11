/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:37:50 by ukim              #+#    #+#             */
/*   Updated: 2020/11/11 22:51:09 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct s_flags
{
    int minus;
    int zero;
    int star;
    int width;
    int precision;
    int dot;
}               t_flags;

int			ft_atoi(char **str);
int			ft_print_c(t_flags *flag, va_list ap);
int			ft_print_str(t_flags *flag, va_list ap);
void		change_star(t_flags *flag, va_list ap);


#endif