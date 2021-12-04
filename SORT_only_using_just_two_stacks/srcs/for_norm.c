/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:15:49 by ukim              #+#    #+#             */
/*   Updated: 2021/04/01 13:34:58 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	norm_bb(t_info *all_info, int *arr, t_list **tal, t_list **tbl)
{
	while (arr[1] < arr[3] && arr[2] < arr[4])
		if ((*tal)->content < (*tbl)->content)
		{
			(*tal) = (*tal)->next;
			write_add_pbrb(all_info);
			arr[1]++;
		}
		else
		{
			(*tbl) = (*tbl)->next;
			write_add_rb(all_info);
			arr[2]++;
		}
}

void	norm_bb_at(t_info *all_info, int *arr, t_list **tal, t_list **tbl)
{
	if (arr[1] < arr[3])
		while (arr[1] < arr[3])
		{
			(*tal) = (*tal)->next;
			write_add_pbrb(all_info);
			arr[1]++;
		}
	else
		while (arr[2] < arr[4])
		{
			(*tbl) = (*tbl)->next;
			write_add_rb(all_info);
			arr[2]++;
		}
}

void	norm_ba(t_info *all_info, int *arr, t_list **tal, t_list **tbl)
{
	while (arr[1] < arr[3] && arr[2] < arr[4])
		if ((*tbl)->content < (*tal)->content)
		{
			(*tbl) = (*tbl)->next;
			write_add_para(all_info);
			arr[2]++;
		}
		else
		{
			(*tal) = (*tal)->next;
			write_add_ra(all_info);
			arr[1]++;
		}
}

void	norm_ba_at(t_info *all_info, int *arr, t_list **tal, t_list **tbl)
{
	if (arr[1] < arr[3])
		while (arr[1] < arr[3])
		{
			(*tal) = (*tal)->next;
			write_add_ra(all_info);
			arr[1]++;
		}
	else
		while (arr[2] < arr[4])
		{
			(*tbl) = (*tbl)->next;
			write_add_para(all_info);
			arr[2]++;
		}
}
