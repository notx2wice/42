/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 23:30:34 by ukim              #+#    #+#             */
/*   Updated: 2020/10/07 14:17:53 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int val, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)(src + i) == (unsigned char)val)
			return ((void*)(src + i));
		i++;
	}
	return (NULL);
}
