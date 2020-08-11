/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:27:17 by ukim              #+#    #+#             */
/*   Updated: 2020/08/08 16:36:23 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		idx;
	int		tmin;

	if (min >= max)
	{
		range = 0;
		return (0);
	}
	*range = (int*)malloc(sizeof(int) * (max - min));
	idx = 0;
	tmin = min;
	while (tmin < max)
	{
		(*range)[idx] = min;
		idx++;
		tmin++;
	}
	return (max - tmin);
}
