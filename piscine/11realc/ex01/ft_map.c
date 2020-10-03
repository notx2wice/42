/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 10:03:59 by ukim              #+#    #+#             */
/*   Updated: 2020/08/19 10:12:48 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		*ans;
	int		x;

	ans = (int*)malloc(sizeof(int) * length);
	x = 0;
	while (x < length)
	{
		ans[x] = f(tab[x]);
		x++;
	}
	return (ans);
}
