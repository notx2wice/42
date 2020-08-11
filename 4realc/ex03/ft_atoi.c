/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:03:55 by ukim              #+#    #+#             */
/*   Updated: 2020/08/05 21:42:30 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_space(char c)
{
	if (c == '\t' || c == '\r' || c == '\f')
		return (1);
	else if (c == '\v' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int		num_start;
	int		num_end;
	int		minusc;
	int		answer;

	answer = 0;
	num_end = 0;
	minusc = 0;
	while (check_space(str[num_end]))
		num_end++;
	while (str[num_end] == '+' || str[num_end] == '-')
	{
		if (str[num_end] == '-')
			minusc++;
		num_end++;
	}
	num_start = num_end;
	while (str[num_end] <= '9' && str[num_end] >= '0')
		answer = answer * 10 + (str[num_end++] - '0');
	if (minusc % 2 == 0)
		return (answer);
	return (-1 * answer);
}
