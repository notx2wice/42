/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:56:35 by ukim              #+#    #+#             */
/*   Updated: 2020/08/09 06:30:45 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*null_str(void)
{
	char	*tans;

	tans = (char*)malloc(sizeof(char));
	*tans = 0;
	return (tans);
}

int		get_long(char *str)
{
	int		idx;

	idx = 0;
	while (str[idx])
	{
		idx++;
	}
	return (idx);
}

void	merge(char **strs, char *sep, char *ans, int size)
{
	int		x;
	int		y;
	int		asn_idx;

	x = 0;
	y = 0;
	ans_idx = 0;
	while (x < size)
	{
		y = 0;
		while (y < get_long(strs[x]))
			ans[ans_idx++] = strs[x][y++];
		if (x < size - 1)
		{
			y = 0;
			while (y < get_long(sep))
				ans[ans_idx++] = sep[y++];
		}
	}
	ans[ans_idx] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		idx;
	int		ans_long;
	char	*ans;

	idx = 0;
	if (size == 0)
	{
		ans = null_str();
		return (ans);
	}
	ans_long = get_long(sep) * (size - 1);
	while (idx < size)
		ans_long += get_long(strs[idx++]);
	ans = (char*)malloc(sizeof(char) * (length + 1));
	merge(strs, sep, result, size);
	return (ans);
}
