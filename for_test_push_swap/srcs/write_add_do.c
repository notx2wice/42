/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_add_do.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:03:40 by ukim              #+#    #+#             */
/*   Updated: 2021/04/01 13:34:48 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	write_add_rb(t_info *all_info)
{
	do_rb(all_info);
	write(1, "rb\n", 3);
	all_info->op_n += 1;
}

void	write_add_pbrb(t_info *all_info)
{
	do_pb(all_info);
	do_rb(all_info);
	write(1, "pb\nrb\n", 6);
	all_info->op_n += 2;
}

void	write_add_ra(t_info *all_info)
{
	do_ra(all_info);
	write(1, "ra\n", 3);
	all_info->op_n += 1;
}

void	write_add_para(t_info *all_info)
{
	do_pa(all_info);
	do_ra(all_info);
	write(1, "pa\nra\n", 6);
	all_info->op_n += 2;
}
