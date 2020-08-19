/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 10:34:01 by ukim              #+#    #+#             */
/*   Updated: 2020/08/19 17:36:57 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	x;
	int flag;

	x = 0;
	flag = 0;
	while (x + 1 < length)
	{
		if (flag == 0)
		{
			flag = f(tab[x], tab[x + 1]);
		}
		else if (flag > 0)
		{
			if (f(tab[x], tab[x + 1]) < 0)
				return (0);
		}
		else if (flag < 0)
		{
			if (f(tab[x], tab[x + 1]) > 0)
				return (0);
		}
		x++;
	}
	return (1);
}
