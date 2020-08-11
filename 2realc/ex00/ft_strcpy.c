/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:42:15 by ukim              #+#    #+#             */
/*   Updated: 2020/08/10 17:55:40 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int x;

	x = 0;
	while (*(src + x) != '\0')
	{
		*(dest + x) = *(src + x);
		x++;
	}
	*(dest + x) = *(src + x);
	return (dest);
}
