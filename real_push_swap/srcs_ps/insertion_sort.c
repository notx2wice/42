/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:44:48 by ukim              #+#    #+#             */
/*   Updated: 2021/04/01 10:51:13 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	short_rotate(int left, t_info *all_info, int max_idx)
{
	int	idx;

	idx = 0;
	if (max_idx <= left / 2)
		while (idx < max_idx)
		{
			do_rb(all_info);
			all_info->op_n++;
			write(1, "rb\n", 3);
			idx++;
		}
	else
		while (max_idx < left)
		{
			do_rrb(all_info);
			all_info->op_n++;
			write(1, "rrb\n", 4);
			max_idx++;
		}
	do_pa(all_info);
	all_info->op_n++;
	write(1, "pa\n", 3);
}

void	max_find_push_to_stacka(t_info *all_info, int *left)
{
	int		max;
	int		max_idx;
	int		idx;
	t_list	*tl;

	max = -2147483648;
	tl = all_info->stack_b;
	idx = 0;
	while (tl)
	{
		if (max < tl->content)
		{
			max = tl->content;
			max_idx = idx;
		}
		tl = tl->next;
		idx++;
	}
	short_rotate(*left, all_info, max_idx);
	(*left)--;
}

void	insertion_sort(t_info *all_info, int left)
{
	int		idx;
	int		ileft;
	int		tleft;

	ileft = (all_info->chunked_n < left) && (left \
	<= all_info->aleft + all_info->chunked_n) ? left : all_info->chunked_n;
	tleft = (all_info->chunked_n < left) && (left \
	<= all_info->aleft + all_info->chunked_n) ? left : all_info->chunked_n;
	idx = 0;
	while (idx < ileft)
	{
		do_pb(all_info);
		write(1, "pb\n", 3);
		all_info->op_n++;
		idx++;
	}
	while (ileft != 0)
		max_find_push_to_stacka(all_info, &ileft);
	while (tleft != 0)
	{
		do_ra(all_info);
		write(1, "ra\n", 3);
		all_info->op_n++;
		tleft--;
	}
}
