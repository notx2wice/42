/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:39:33 by ukim              #+#    #+#             */
/*   Updated: 2020/08/05 14:54:18 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int x;

	x = 0;
	while (s1[x] != '\0' && s2[x] != '\0' && x < n)
	{
		if (s1[x] > s2[x])
			return (1);
		if (s1[x] < s2[x])
			return (-1);
		x++;
	}
	if (x == n)
		return (0);
	else if (s1[x] == '\0' && s2[x] == '\0')
		return (0);
	else if (s1[x] == '\0')
		return (-1);
	return (1);
}
