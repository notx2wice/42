/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:50:44 by ukim              #+#    #+#             */
/*   Updated: 2020/08/10 20:04:05 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	x;
	int size_i;

	x = 0;
	size_i = (int)size;
	while (x + 1 < size_i && src[x] != '\0')
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	while (src[x])
		x++;
	return (x);
}
