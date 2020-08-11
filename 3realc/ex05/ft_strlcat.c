/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:09:07 by ukim              #+#    #+#             */
/*   Updated: 2020/08/10 17:28:01 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_sz;
	unsigned int	idx;

	dest_sz = 0;
	while (dest[dest_sz] != '\0')
		dest_sz++;
	idx = 0;
	while (src[idx] != '\0' && idx + dest_sz + 1 < size)
	{
		dest[dest_sz + idx] = src[idx];
		idx++;
	}
	dest[dest_sz + idx] = '\0';
	while (src[idx] != '\0')
		idx++;
	if (dest_sz > size)
		return (idx + size);
	return (dest_sz + idx);
}
