/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 22:00:54 by ukim              #+#    #+#             */
/*   Updated: 2021/03/24 16:58:43 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	tmp = 0;
	if (lst == 0 || *lst == 0)
		return ;
	tmp = *lst;
	while (*lst)
	{
		*lst = tmp->next;
		free(tmp);
		tmp = *lst;
	}
	*lst = 0;
}
