/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:35:21 by ukim              #+#    #+#             */
/*   Updated: 2021/04/01 13:36:20 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_stack(t_info *all_info)
{
	t_list	*ta;
	t_list	*tb;

	ta = all_info->stack_a;
	tb = all_info->stack_b;
	printf("         top_stacka          top_stackb     \n");
	while (ta && tb)
	{
		printf("     %10d%20d     \n", ta->content, tb->content);
		ta = ta->next;
		tb = tb->next;
	}
	if (ta)
	{
		while (ta)
		{
			printf("     %10d%20.d     \n", ta->content, 0);
			ta = ta->next;
		}
	}
	if (tb)
	{
		while (tb)
		{
			printf("     %10.d%20d     \n", 0, tb->content);
			tb = tb->next;
		}
	}
	write(1, "\n\n", 2);
}
