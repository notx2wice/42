/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 18:19:10 by ukim              #+#    #+#             */
/*   Updated: 2020/08/17 10:14:18 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void				str_print(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void				recur_int_print(int n)
{
	char temp;

	temp = n % 10 + '0';
	if (n >= 10)
		recur_int_print(n / 10);
	write(1, &temp, 1);
}

void				print_int(int n)
{
	recur_int_print(n);
	write(1, "\n", 1);
}

void				ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		str_print(par[i].str);
		print_int(par[i].size);
		str_print(par[i].copy);
		i++;
	}
}
