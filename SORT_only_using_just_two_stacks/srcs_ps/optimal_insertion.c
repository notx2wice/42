/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_insertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:49:01 by ukim              #+#    #+#             */
/*   Updated: 2021/04/01 11:02:17 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	no_rotate_pushb(t_info *all_info, int max_idx, int n)
{
	int	idx;

	idx = 0;
	if (max_idx <= n / 2)
		while (idx < max_idx)
		{
			do_ra(all_info);
			all_info->op_n++;
			write(1, "ra\n", 3);
			idx++;
		}
	else
	{
		while (max_idx < n)
		{
			do_rra(all_info);
			all_info->op_n++;
			write(1, "rra\n", 4);
			max_idx++;
		}
	}
	do_pb(all_info);
	all_info->op_n++;
	write(1, "pb\n", 3);
}

void	min_find_push_to_stackb(t_info *all_info, int n)
{
	int		max;
	int		max_idx;
	int		idx;
	t_list	*tl;

	max = 2147483647;
	tl = all_info->stack_a;
	idx = 0;
	while (tl)
	{
		if (max > tl->content)
		{
			max = tl->content;
			max_idx = idx;
		}
		tl = tl->next;
		idx++;
	}
	no_rotate_pushb(all_info, max_idx, n);
}

void	write_add_sa(t_info *all_info)
{
	do_sa(all_info);
	write(1, "sa\n", 3);
	all_info->op_n++;
}

void	optimal_insertion(t_info *all_info)
{
	int		idx;

	idx = 0;
	if (all_info->n == 1)
		return ;
	else if (all_info->n == 2)
		if (all_info->stack_a->content > ft_lstlast(all_info->stack_a)->content)
			write_add_sa(all_info);
	while (idx < all_info->n - 2)
	{
		min_find_push_to_stackb(all_info, all_info->n - idx);
		idx++;
	}
	if (all_info->stack_a->content > all_info->stack_a->next->content)
		write_add_sa(all_info);
	while (idx > 0)
	{
		do_pa(all_info);
		write(1, "pa\n", 3);
		all_info->op_n++;
		idx--;
	}
}
