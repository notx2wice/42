/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 11:44:41 by ukim              #+#    #+#             */
/*   Updated: 2020/08/05 11:46:35 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int temp;
	int front;
	int end;

	front = 0;
	end = size - 1;
	while (front < size / 2)
	{
		temp = *(tab + front);
		*(tab + front) = *(tab + end);
		*(tab + end) = temp;
		front++;
		end--;
	}
}
