/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekim <ekim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:47:57 by ekim              #+#    #+#             */
/*   Updated: 2020/11/09 20:55:24 by ekim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int		mvag(va_list ap)
{
	int c = va_arg(ap,int);
	printf("%d\n", c);
	return(0);
}

int		argcheck(int argc, ...)
{
	int		i;
	va_list ap;

	va_start(ap, argc);

	int num = va_arg(ap, int);
	mvag(ap);

	va_end(ap);
	return (num);
}

int		main(void)
{
	int		check;
	check = argcheck(4, 10, 20, 30, 40);
	printf("%d", check);
}
