/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 20:17:37 by ukim              #+#    #+#             */
/*   Updated: 2021/04/01 13:30:36 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_info
{
	int				n;
	int				op_n;
	int				*sorted_arr;
	int				*for_sort_tarr;
	int				chunked_n;
	int				chunked_size;
	int				k;
	int				aleft;
	t_list			*stack_a;
	t_list			*stack_b;
}					t_info;

void				print_stack(t_info *all_info);
void				do_sa(t_info *all_info);
void				do_sb(t_info *all_info);
void				do_ss(t_info *all_info);
void				do_rrr(t_info *all_info);
void				do_rrb(t_info *all_info);
void				do_rra(t_info *all_info);
void				do_rr(t_info *all_info);
void				do_rb(t_info *all_info);
void				do_ra(t_info *all_info);
void				do_pa(t_info *all_info);
void				do_pb(t_info *all_info);

void				set_all_info(t_info **all_info, int ac);

int					input_check(t_info *all_info);
void				input_value_tolist(t_info *all_info);

void				merge(t_info *all_info, int start, int mid, int end);
void				dfs(t_info *all_info, int start, int end);
void				sort_array(t_info	*all_info);
void				make_instructionss(t_info *all_info);
void				insertion_sort(t_info *all_info, int left);
void				merge_sort(t_info *all_info, int idx);
void				optimal_insertion(t_info *all_info);

void				write_add_rb(t_info *all_info);
void				write_add_pbrb(t_info *all_info);
void				write_add_ra(t_info *all_info);
void				write_add_para(t_info *all_info);

void				norm_ba(t_info *all_info, int *arr, t_list **talist, t_list **tblist);
void				norm_bb(t_info *all_info, int *arr, t_list **talist, t_list **tblist);
void				norm_ba_at(t_info *all_info, int *arr, t_list **talist, t_list **tblist);
void				norm_bb_at(t_info *all_info, int *arr, t_list **talist, t_list **tblist);

void				free_all(t_info *all_info);

#endif
