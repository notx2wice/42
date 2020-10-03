/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:27:17 by ukim              #+#    #+#             */
/*   Updated: 2020/08/15 12:46:26 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		idx;

	if (min >= max)
	{
		range = 0;
		return (0);
	}
	*range = (int*)malloc(sizeof(int) * (max - min));
	idx = 0;
	while (min + idx < max)
	{
		(*range)[idx] = min + idx;
		idx++;
	}
	return (max - tmin);
}
