/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 21:13:34 by ukim              #+#    #+#             */
/*   Updated: 2020/10/04 01:20:14 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	size_t	i;

	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(unsigned char*)(ptr + i) = (unsigned char)value;
		i++;
	}
	return (ptr);
}
/*
** 바이트 단위로 변경한다. 값을 value의 값으로
*/
