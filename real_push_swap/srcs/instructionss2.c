/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionss2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:12:45 by ukim              #+#    #+#             */
/*   Updated: 2021/03/31 19:43:26 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		do_ra(t_info *all_info)
{
	t_list *ta;
	t_list *temp;

	ta = all_info->stack_a;
	if (ft_lstsize(all_info->stack_a) <= 1)
		return ;
	all_info->stack_a = ta->next;
	temp = ft_lstlast(all_info->stack_a);
	temp->next = ta;
	ta->next = NULL;
}

void		do_rb(t_info *all_info)
{
	t_list *tb;
	t_list *temp;

	tb = all_info->stack_b;
	if (ft_lstsize(all_info->stack_b) <= 1)
		return ;
	all_info->stack_b = tb->next;
	temp = ft_lstlast(all_info->stack_b);
	temp->next = tb;
	tb->next = NULL;
}

void		input_value_tolist(t_info *all_info)
{
	int		idx;
	t_list	*temp_l;

	idx = 0;
	while (idx < all_info->n)
	{
		temp_l = ft_lstnew(all_info->sorted_arr[idx]);
		ft_lstadd_back(&all_info->stack_a, temp_l);
		idx++;
	}
}

int			input_check(t_info *all_info)
{
	int idx;

	idx = 0;
	while (idx < all_info->n - 1)
	{
		if (all_info->sorted_arr[idx] == all_info->sorted_arr[idx + 1])
			return (0);
		idx++;
	}
	return (1);
}

void		set_all_info(t_info **all_info, int ac)
{
	(*all_info) = (t_info*)malloc(sizeof(t_info));
	(*all_info)->n = ac - 1;
	(*all_info)->sorted_arr = (int*)malloc(sizeof(int) * (*all_info)->n);
	(*all_info)->for_sort_tarr = (int*)malloc(sizeof(int) * (*all_info)->n);
	(*all_info)->stack_a = NULL;
	(*all_info)->stack_b = NULL;
}
