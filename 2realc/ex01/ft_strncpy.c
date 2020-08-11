/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 14:24:09 by ukim              #+#    #+#             */
/*   Updated: 2020/08/10 18:02:38 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	x;
	int				check;

	x = 0;
	check = 0;
	while (x < n)
	{
		if (check == 1 || src[x] == '\0')
		{
			dest[x] = '\0';
			check = 1;
		}
		else
			dest[x] = src[x];
		x++;
	}
	return (dest);
}
