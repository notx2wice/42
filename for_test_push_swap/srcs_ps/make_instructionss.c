/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_instructionss.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:05:46 by ukim              #+#    #+#             */
/*   Updated: 2021/04/01 11:56:54 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void				set_chunked_size(t_info *all_info)
{
	double			ln2;
	int				tk;
	int				tchunk;
	double			tq;

	tk = 1;
	tchunk = 1;
	ln2 = 0.69314;
	tq = (all_info->n * ln2) / 12.0;
	while (tq > 1)
	{
		tq /= 2;
		tk++;
		tchunk *= 2;
	}
	all_info->k = --tk;
	all_info->chunked_size = tchunk;
	all_info->chunked_n = all_info->n / tchunk;
	all_info->aleft = (all_info->n - \
	(all_info->chunked_size * all_info->chunked_n));
}

void				write_add_pb(t_info *all_info, int *idx)
{
	do_pb(all_info);
	write(1, "pb\n", 3);
	do_rb(all_info);
	write(1, "rb\n", 3);
	all_info->op_n += 2;
	(*idx)++;
}

void				make_instructionss(t_info *all_info)
{
	int				idx;
	int				left;
	int				tk;

	tk = all_info->chunked_n;
	left = all_info->n;
	idx = 0;
	set_chunked_size(all_info);
	if (all_info->k != 0)
		while (idx < all_info->chunked_size)
		{
			insertion_sort(all_info, left);
			idx++;
			left -= all_info->chunked_n;
		}
	else
		optimal_insertion(all_info);
	idx = 0;
	if (all_info->k != 0)
		while (idx < ((all_info->n - all_info->aleft) / 2))
			write_add_pb(all_info, &idx);
	idx = -1;
	if (all_info->k != 0)
		while (++idx < all_info->k)
			merge_sort(all_info, idx);
}
