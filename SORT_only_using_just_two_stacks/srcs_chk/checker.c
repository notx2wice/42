/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 22:19:56 by ukim              #+#    #+#             */
/*   Updated: 2021/04/01 13:47:24 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		inst_check(char *line)
{
	if (!ft_strcmp(line, "sa"))
		return (1);
	else if (!ft_strcmp(line, "sb"))
		return (1);
	else if (!ft_strcmp(line, "ss"))
		return (1);
	else if (!ft_strcmp(line, "pb"))
		return (1);
	else if (!ft_strcmp(line, "pa"))
		return (1);
	else if (!ft_strcmp(line, "ra"))
		return (1);
	else if (!ft_strcmp(line, "rb"))
		return (1);
	else if (!ft_strcmp(line, "rr"))
		return (1);
	else if (!ft_strcmp(line, "rra"))
		return (1);
	else if (!ft_strcmp(line, "rrb"))
		return (1);
	else if (!ft_strcmp(line, "rrr"))
		return (1);
	else
		return (0);
}

void	do_inst(char *line, t_info *all_info)
{
	if (!ft_strcmp(line, "sa"))
		do_sa(all_info);
	else if (!ft_strcmp(line, "sb"))
		do_sb(all_info);
	else if (!ft_strcmp(line, "ss"))
		do_ss(all_info);
	else if (!ft_strcmp(line, "pb"))
		do_pb(all_info);
	else if (!ft_strcmp(line, "pa"))
		do_pa(all_info);
	else if (!ft_strcmp(line, "ra"))
		do_ra(all_info);
	else if (!ft_strcmp(line, "rb"))
		do_rb(all_info);
	else if (!ft_strcmp(line, "rr"))
		do_rr(all_info);
	else if (!ft_strcmp(line, "rra"))
		do_rra(all_info);
	else if (!ft_strcmp(line, "rrb"))
		do_rrb(all_info);
	else if (!ft_strcmp(line, "rrr"))
		do_rrr(all_info);
}

void	get_instructionss(t_info *all_info)
{
	char	*line;
	int		res;

	line = 0;
	while ((res = get_next_line(0, &line)))
	{
		if (!inst_check(line))
		{
			write(1, "wrong input\n", 12);
			free(line);
			continue;
		}
		do_inst(line, all_info);
		print_stack(all_info);
		free(line);
	}
	print_stack(all_info);
}

void	print_result(t_info *all_info)
{
	int			idx;
	t_list		*ltemp;

	idx = 0;
	ltemp = all_info->stack_a;
	while (ltemp)
	{
		if (ltemp->content != all_info->sorted_arr[idx++])
		{
			write(1, "KO\n", 3);
			return ;
		}
		ltemp = ltemp->next;
	}
	write(1, "OK\n", 3);
}

int		main(int ac, char **av)
{
	t_info		*all_info;
	int			idx;
	int			temp;
	int			flag;

	flag = 1;
	idx = 0;
	set_all_info(&all_info, ac);
	if (ac >= 2)
	{
		while (++idx < ac)
		{
			temp = pw_atoi(av[idx], &flag);
			all_info->sorted_arr[idx - 1] = temp;
		}
		input_value_tolist(all_info);
		sort_array(all_info);
		if (!input_check(all_info) || flag == 0)
			write(1, "invalid input\n", 14);
		if (!input_check(all_info) || flag == 0)
			return (0);
		get_instructionss(all_info);
		print_result(all_info);
	}
	free_all(all_info);
}
