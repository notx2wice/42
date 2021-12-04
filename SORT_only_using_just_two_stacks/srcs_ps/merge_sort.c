/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:27:47 by ukim              #+#    #+#             */
/*   Updated: 2021/04/01 13:32:50 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		set_value(int *arr, t_info *all_info, t_list **tal, t_list **tbl)
{
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = all_info->chunked_n;
	arr[4] = all_info->chunked_n;
	*tal = all_info->stack_a;
	*tbl = all_info->stack_b;
}

void		push_backa(t_info *all_info, int idx, int x, int flag)
{
	int		arr[5];
	t_list	*tal;
	t_list	*tbl;

	set_value(arr, all_info, &tal, &tbl);
	while ((all_info->k - idx) + arr[0] < all_info->k)
	{
		arr[3] *= 2;
		arr[4] *= 2;
		arr[0]++;
	}
	if (x + 1 == flag)
		arr[3] += all_info->aleft;
	norm_ba(all_info, arr, &tal, &tbl);
	norm_ba_at(all_info, arr, &tal, &tbl);
}

void		push_backb(t_info *all_info, int idx)
{
	int		arr[5];
	t_list	*tal;
	t_list	*tbl;

	set_value(arr, all_info, &tal, &tbl);
	while ((all_info->k - idx) + arr[0] < all_info->k)
	{
		arr[3] *= 2;
		arr[4] *= 2;
		arr[0]++;
	}
	norm_bb(all_info, arr, &tal, &tbl);
	norm_bb_at(all_info, arr, &tal, &tbl);
}

void		merge_sort(t_info *all_info, int idx)
{
	int		x;
	int		ttime;
	int		tidx;

	x = 0;
	ttime = 1;
	tidx = idx;
	if (tidx < all_info->k - 1)
	{
		while (tidx < (all_info->k - 1))
		{
			ttime *= 2;
			tidx++;
		}
		while (x < ttime / 2)
		{
			push_backb(all_info, idx);
			push_backa(all_info, idx, x, ttime / 2);
			x++;
		}
	}
	else
		push_backa(all_info, idx, ttime / 2 - 1, ttime / 2);
}
