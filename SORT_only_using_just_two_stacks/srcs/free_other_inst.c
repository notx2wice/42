/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_other_inst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:10:37 by ukim              #+#    #+#             */
/*   Updated: 2021/04/01 14:49:48 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		free_all(t_info *all_info)
{
	free(all_info->for_sort_tarr);
	free(all_info->sorted_arr);
	if (all_info->stack_a)
		ft_lstclear(&all_info->stack_a);
	if (all_info->stack_b)
		ft_lstclear(&all_info->stack_b);
}

void		do_rr(t_info *all_info)
{
	do_ra(all_info);
	do_rb(all_info);
}

void		do_rra(t_info *all_info)
{
	t_list *ta;
	t_list *end;
	t_list *bfend;

	ta = all_info->stack_a;
	if (ft_lstsize(all_info->stack_a) <= 1)
		return ;
	end = ft_lstlast(all_info->stack_a);
	bfend = ta;
	while (bfend->next->next)
		bfend = bfend->next;
	bfend->next = NULL;
	all_info->stack_a = end;
	end->next = ta;
}

void		do_rrb(t_info *all_info)
{
	t_list *tb;
	t_list *end;
	t_list *bfend;

	tb = all_info->stack_b;
	if (ft_lstsize(all_info->stack_b) <= 1)
		return ;
	end = ft_lstlast(all_info->stack_b);
	bfend = tb;
	while (bfend->next->next)
		bfend = bfend->next;
	bfend->next = NULL;
	all_info->stack_b = end;
	end->next = tb;
}

void		do_rrr(t_info *all_info)
{
	do_rra(all_info);
	do_rrb(all_info);
}
