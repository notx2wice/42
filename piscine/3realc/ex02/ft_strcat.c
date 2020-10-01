/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:56:43 by ukim              #+#    #+#             */
/*   Updated: 2020/08/05 15:26:14 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		dest_length;
	int		src_length;

	dest_length = 0;
	while (dest[dest_length] != '\0')
		dest_length++;
	src_length = 0;
	while (src[src_length] != '\0')
	{
		dest[dest_length + src_length] = src[src_length];
		src_length++;
	}
	dest[dest_length + src_length] = '\0';
	return (dest);
}
