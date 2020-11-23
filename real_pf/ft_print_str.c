/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekim <ekim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:23:18 by ekim              #+#    #+#             */
/*   Updated: 2020/11/17 21:17:55 by ekim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			str_print_minus(t_flags *flag, char *str)
{
    char			*result;

    if (flag->minus == 0)
        result = ft_left_strcat(str, ' ', (flag->width - ft_strlen(str)));
    else
        result = ft_right_strcat(str, ' ', (flag->width - ft_strlen(str)));
    ft_putstr(result);
    free(result);
    return (ft_strlen(result));
}

static int          str_precision_width_flag(t_flags *flag, char *str)
{
    int             len;
    int             i;
    int             j;
    char            *trim;

    len = ft_strlen(str);
    if (flag->precision < len)
    {
        i = flag->precision;
        j = 0;
        if (!(trim = (char *)malloc(sizeof(char) * (i + 1))))
            return (0);
        while (i--)
            trim[j++] = *str++;
        trim[j] = '\0';
        if (flag->width <= j)
        {
            ft_putstr(trim);
            return (j);
        }
        return (str_print_minus(flag,  trim));
    }
    if (flag->width - len > 0)
        return (str_print_minus(flag, str));
    ft_putstr(str);
    return (ft_strlen(str));
}

static int			str_width_flag(t_flags *flag, char *str)
{
    int				len;

    len = ft_strlen(str);
    if (flag->width != 0)
    {
        if (flag->width <= len)
        {
            ft_putstr(str);
            return (len);
        }
        return (str_print_minus(flag, str));
    }
    ft_putstr(str);
    return (len);
}

int				ft_print_str(t_flags *flag, va_list ap)
{
    char		*str;
    int			count;

    if (!(str = (char *)va_arg(ap, void *)))
        str = "(null)";
    if (flag->pf == 0)
        count = str_width_flag(flag, str);
    else
        count = str_precision_width_flag(flag, str);
    return (count);
}