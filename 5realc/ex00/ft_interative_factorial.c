/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interative_factorial.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:44:51 by ukim              #+#    #+#             */
/*   Updated: 2020/08/06 10:48:52 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_interative_factorial(int nb)
{
	int idx;
	int	result;

	if (nb < 0)
		return (0);
	result = 1;
	idx = 2;
	while (idx <= nb)
	{
		result = result * idx;
		idx++;
	}
	return (result);
}
