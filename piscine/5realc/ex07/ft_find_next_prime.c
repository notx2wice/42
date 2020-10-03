/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 12:20:02 by ukim              #+#    #+#             */
/*   Updated: 2020/08/15 12:37:17 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int x;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	x = 2;
	while (x * x <= nb && x <= 66000)
	{
		if (nb % x == 0)
			return (0);
		x++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
