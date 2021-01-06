/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 22:01:11 by ukim              #+#    #+#             */
/*   Updated: 2020/10/06 16:13:37 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	if (lst == 0)
		return (0);
	if (!(result = ft_lstnew((*f)(lst->content))))
		return (0);
	temp = result;
	lst = lst->next;
	while (lst)
	{
		if (!(temp->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&result, del);
			return (0);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (result);
}
