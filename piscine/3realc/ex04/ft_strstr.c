/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:34:29 by ukim              #+#    #+#             */
/*   Updated: 2020/08/10 17:27:58 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	first;
	int	find_long;
	int	index;
	int flag;

	find_long = 0;
	while (to_find[find_long] != '\0')
		find_long++;
	if (find_long == 0)
		return (str);
	first = -1;
	while (str[++first] != '\0')
	{
		index = -1;
		if (str[first] == to_find[0])
		{
			flag = 1;
			while (++index < find_long - 1)
				if (str[first + index + 1] != to_find[index + 1])
					flag = flag * 0;
			if (flag == 1)
				return (str + first);
		}
	}
	return (0);
}
