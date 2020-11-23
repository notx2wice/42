/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:23:18 by ekim              #+#    #+#             */
/*   Updated: 2020/11/23 17:18:49 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char         *make_trim(char *str, int length)
{
    char            *trim;
    int             i;

    if (!(trim = (char *)malloc(sizeof(char) * (length + 1))))
            return (0);
    i = 0;
    while (length--)
        trim[i++] = *str++;
    trim[i] = '\0';
    return (trim);
}

static int          str_print(char *str)
{
    write(1, str, ft_strlen(str));
    return (ft_strlen(str));
}

int              str_print_minus(t_flags *flag, char *str, char c)
{
    char         *result;
    int             len;

    if (flag->minus == 0)
        result = ft_left_strcat(str, c, (flag->width - ft_strlen(str)));
    else
        result = ft_right_strcat(str, c, (flag->width - ft_strlen(str)));
    ft_putstr(result);
    len = ft_strlen(result);
    free(result);
    return (len);
}

static int          str_precision_width_flag(t_flags *flag, char *str)
{
    int             len;
    int             t_len;
    int             m_precision;
    char            *trim;

    len = ft_strlen(str);
    m_precision = flag->precision;
    if (flag->precision < 0)
        m_precision *= (-1);
    if (m_precision < len)
    {
        trim = make_trim(str, m_precision);
        t_len = ft_strlen(trim);
        if (flag->width <= t_len)
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
    return (str_print(str));
}

static int         str_width_flag(t_flags *flag, char *str)
{
    if (flag->width != 0)
    {
        if (flag->width > ft_strlen(str))
            return (str_print_minus(flag, str, ' '));
    }
    return (str_print(str));
}

int            ft_print_str(t_flags *flag, va_list ap)
{
    char      *str;
    int         count;

    if (!(str = (char *)va_arg(ap, void *)))
        str = "(null)";
    if (flag->pf == 0)
        count = str_width_flag(flag, str);
    else
        count = str_precision_width_flag(flag, str);
    return (count);
}