/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekim <ekim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:45:05 by ukim              #+#    #+#             */
/*   Updated: 2020/12/19 16:03:45 by ekim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	s1_letter;
	unsigned char	s2_letter;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	s1_letter = (unsigned char)s1[i];
	s2_letter = (unsigned char)s2[i];
	return ((int)(s1_letter - s2_letter));
}
