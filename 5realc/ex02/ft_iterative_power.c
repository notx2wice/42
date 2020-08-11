/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 11:59:26 by ukim              #+#    #+#             */
/*   Updated: 2020/08/08 12:04:51 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int	answer;

	if (power < 0)
		return (0);
	answer = 1;
	while (power > 0)
	{
		answer = answer * nb;
		power--;
	}
	return (answer);
}
