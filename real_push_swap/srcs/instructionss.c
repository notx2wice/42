/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:24:36 by ukim              #+#    #+#             */
/*   Updated: 2021/03/31 19:39:07 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		do_sa(t_info *all_info)
{
	t_list	*ta;
	t_list	*tta;
	int		temp;

	ta = all_info->stack_a;
	if (!ta)
		return ;
	if (ft_lstsize(ta) < 2)
		return ;
	tta = ta->next;
	temp = ta->content;
	ta->content = tta->content;
	tta->content = temp;
}

void		do_sb(t_info *all_info)
{
	t_list	*ta;
	t_list	*tta;
	int		temp;

	ta = all_info->stack_b;
	if (!ta)
		return ;
	if (ft_lstsize(ta) < 2)
		return ;
	tta = ta->next;
	temp = ta->content;
	ta->content = tta->content;
	tta->content = temp;
}

void		do_ss(t_info *all_info)
{
	do_sa(all_info);
	do_sb(all_info);
}

void		do_pb(t_info *all_info)
{
	t_list	*ta;
	t_list	*tb;

	ta = all_info->stack_a;
	tb = all_info->stack_b;
	if (!ta)
		return ;
	all_info->stack_a = ta->next;
	ta->next = tb;
	all_info->stack_b = ta;
}

void		do_pa(t_info *all_info)
{
	t_list	*ta;
	t_list	*tb;

	ta = all_info->stack_a;
	tb = all_info->stack_b;
	if (!tb)
		return ;
	all_info->stack_b = tb->next;
	tb->next = ta;
	all_info->stack_a = tb;
}
