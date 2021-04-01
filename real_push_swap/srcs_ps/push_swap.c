/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 22:19:56 by ukim              #+#    #+#             */
/*   Updated: 2021/04/01 15:17:54 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_answer(t_info *all_info)
{
	int	idx;

	idx = 0;
	while (idx < all_info->n - 1)
	{
		if (all_info->sorted_arr[idx] > all_info->sorted_arr[idx + 1])
			return (0);
		idx++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_info		*all_info;
	int			idx;
	int			flag;

	flag = 1;
	idx = 0;
	set_all_info(&all_info, ac);
	if (ac >= 2)
	{
		while (++idx < ac)
			all_info->sorted_arr[idx - 1] = pw_atoi(av[idx], &flag);
		if (is_answer(all_info))
			return (0);
		input_value_tolist(all_info);
		sort_array(all_info);
		if (!input_check(all_info) || flag == 0)
			write(1, "invalid input\n", 14);
		if (!input_check(all_info) || flag == 0)
			return (0);
		make_instructionss(all_info);
	}
	free_all(all_info);
}
