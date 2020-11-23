/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 00:34:26 by ukim              #+#    #+#             */
/*   Updated: 2020/10/08 17:22:05 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	s1_letter;
	unsigned char	s2_letter;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && (size_t)i < n)
	{
		i++;
	}
	if ((size_t)i == n)
		return (0);
	s1_letter = (unsigned char)s1[i];
	s2_letter = (unsigned char)s2[i];
	return (s1_letter - s2_letter);
}
