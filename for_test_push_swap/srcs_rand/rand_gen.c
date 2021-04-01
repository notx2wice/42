/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:48:36 by ukim              #+#    #+#             */
/*   Updated: 2021/04/01 14:50:43 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <time.h>

int arr[10000];
int n;

int		double_check(int random, int n)
{
	int	idx;

	idx = 0;
	while (idx < n)
	{
		if (arr[idx] == random)
			return (0);
		idx++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int	random;
	int	minus;
	int	idx;

	idx = 0;
	srand(time(NULL));
	if (ac == 2)
	{
		n = ft_atoi(av[1]);
		if (n <= 0)
			return (0);
		while (idx < n)
		{
			if (rand() % 2 == 1)
			{
				minus = -1;
			}
			else
				minus = 1;
			random = minus * (rand() % (2 * n));
			if (double_check(random, idx))
			{
				arr[idx] = random;
				idx++;
			}
			else
				continue;
		}
	}
	idx = 0;
	while (idx < n - 1)
		printf("%d ", arr[idx++]);
	printf("%d \n", arr[idx]);
}
