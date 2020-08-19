/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 10:34:01 by ukim              #+#    #+#             */
/*   Updated: 2020/08/19 11:10:48 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	x;
	int flag;

	flag = 0;
	x = 0;
	while (x + 1 < length)
	{
		if (f(tab[x], tab[x + 1]) != 0)
			flag = f(tab[x], tab[x + 1]);
		x++;
	}
	x = 0;
	while (x + 1 < length)
	{
		if (f(tab[x], tab[x + 1]) == 0)
		{
			x++;
			continue ;
		}
		if (flag != f(tab[x], tab[x + 1]))
			return (0);
		x++;
	}
	return (1);
}
