/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_merge_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 08:16:16 by ukim              #+#    #+#             */
/*   Updated: 2021/03/31 19:32:14 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	after_work(t_info *all_info, int *arr, int mid, int end)
{
	if (arr[0] <= mid)
		while (arr[0] <= mid)
		{
			all_info->for_sort_tarr[arr[2]] = all_info->sorted_arr[arr[0]];
			arr[0]++;
			arr[2]++;
		}
	if (arr[1] <= end)
		while (arr[1] <= end)
		{
			all_info->for_sort_tarr[arr[2]] = all_info->sorted_arr[arr[1]];
			arr[1]++;
			arr[2]++;
		}
	while (arr[3] <= end)
	{
		all_info->sorted_arr[arr[3]] = all_info->for_sort_tarr[arr[3]];
		arr[3]++;
	}
}

void	merge(t_info *all_info, int start, int mid, int end)
{
	int		arr[4];

	if (start >= end)
		return ;
	arr[0] = start;
	arr[1] = mid + 1;
	arr[2] = start;
	arr[3] = start;
	while (arr[0] <= mid && arr[1] <= end)
		if (all_info->sorted_arr[arr[0]] < all_info->sorted_arr[arr[1]])
		{
			all_info->for_sort_tarr[arr[2]] = all_info->sorted_arr[arr[0]];
			arr[0]++;
			arr[2]++;
		}
		else
		{
			all_info->for_sort_tarr[arr[2]] = all_info->sorted_arr[arr[1]];
			arr[1]++;
			arr[2]++;
		}
	after_work(all_info, arr, mid, end);
}

void	dfs(t_info *all_info, int start, int end)
{
	int		mid;

	if (start >= end)
		return ;
	mid = (start + end) / 2;
	dfs(all_info, start, mid);
	dfs(all_info, mid + 1, end);
	merge(all_info, start, mid, end);
}

void	sort_array(t_info *all_info)
{
	dfs(all_info, 0, all_info->n - 1);
}
