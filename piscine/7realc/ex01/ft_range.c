/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:21:14 by ukim              #+#    #+#             */
/*   Updated: 2020/08/08 16:26:30 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*result;
	int		idx;

	if (min >= max)
		return (0);
	result = (int*)malloc(sizeof(int) * (max - min));
	idx = 0;
	while (min + idx < max)
	{
		result[idx] = min + idx;
		idx++;
	}
	return (result);
}
