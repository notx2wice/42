/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:56:32 by ukim              #+#    #+#             */
/*   Updated: 2020/08/10 18:16:56 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check(int x, char *str)
{
	int index;

	index = x - 1;
	if (index == -1)
		return (1);
	else if (str[index] >= '0' && str[index] <= '9')
		return (0);
	else if (str[index] >= 'a' && str[index] <= 'z')
		return (0);
	else if (str[index] >= 'A' && str[index] <= 'Z')
		return (0);
	else
		return (1);
}

void	row_case(int x, char *str)
{
	if (str[x] <= 'Z' && str[x] >= 'A')
		str[x] = str[x] + 32;
}

void	upper_case(int x, char *str)
{
	if (str[x] <= 'z' && str[x] >= 'a')
		str[x] = str[x] - 32;
}

char	*ft_strcapitalize(char *str)
{
	int		x;

	x = 0;
	while (str[x] != '\0')
	{
		if (check(x, str))
			upper_case(x, str);
		else
			row_case(x, str);
		x++;
	}
	return (str);
}
