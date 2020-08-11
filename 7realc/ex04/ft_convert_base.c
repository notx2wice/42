/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:04:35 by ukim              #+#    #+#             */
/*   Updated: 2020/08/11 14:25:54 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_base_num(char c, char *base);
void	compact(char *arr, int interval);
void	init_arr(char *arr, int size);
int		get_len(char *str);

int		is_valid(char *base)
{
	int	x;
	int	y;

	if (base[0] == 0 || base[1] == 0)
		return (0);
	x = 0;
	while (base[x])
	{
		if (base[x] == '+' || base[x] == '-'
				|| base[x] == '\t' || base[x] == '\f' 
				|| base[x] == '\n' || base[x] == '\v' 
				|| base[x] == '\r' || base[x] == ' ')
			return (0);
		y = x + 1;
		while (base[y])
		{
			if (base[x] ==  base[y])
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int		check_char(char c, char *base)
{
	int x;

	x = 0;
	if (c == '\t' || c == '\f' || c == '\n'
			|| c == '\v'|| c =='\r' || c ==' ')
		return (1);
	if (c == '-')
		return (-1);
	if (c == '+')
		return (-2);
	while (base[x] != '\0')
	{
		if (c == base[x++])
			return (2);
	}
	return (0);
}

int		base_to_int(char *str, char *base, int length)
{
	int idx;
	int cnt;
	int rslt;

	idx = 0;
	while (check_char(str[idx],base) == 1)
		idx++;
	cnt = 1;
	while (check_char(str[idx],base) < 0)
	{
		if (check_char(str[idx],base) == -1)
			cnt = cnt * -1;
		idx++;
	}
	if (check_char(str[idx], base) != 2)
		return (0);
	rslt = get_base_num(str[idx++],base);
	length = get_len(base);
	while (check_char(str[idx], base) == 2)
		rslt = rslt * length + get_base_num(str[idx++], base);
	return (rslt * count);	
}

char	*int_to_base(int nbr, char *base, int len)
{
	char	*rslt;
	int		x;

	rslt = (char*)malloc(sizeof(char) * 34);
	x = 0;
	while (x < 34)
		rslt[x++] = 0;
	if (nbr < 0)
	{
		rslt[0] = '-';
		nbr = nbr * -1;
	}
	x = 33;
	while (nbr / len)
	{
		rslt[x] = base[nbr % len];
		nbr /= len;
		x--;
	}
	rslt[x] = base[nbr % len];
	compact(rslt, x);
	return (rslt);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		len_from;
	int		len_to;
	int		tmp;

	len_from = get_len(base_from);
	len_to = get_len(base_to);
	if (!is_valid(base_from) || !is_valid(base_to))
		return (0);
	tmp = base_to_int(nbr, base_from, len_from);
	return (int_to_base(temp, base_to, len_to));
}
