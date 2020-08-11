/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 06:20:27 by ukim              #+#    #+#             */
/*   Updated: 2020/08/10 20:47:14 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	ox_make(int n)
{
	if (n < 10)
		return (n + '0');
	return (n + 'a' - 10);
}

void			print_address(void *addr)
{
	unsigned char	address[17];
	int				index;
	long			temp;

	address[16] = ':';
	index = 15;
	temp = (long)addr;
	while (index >= 0)
	{
		address[index] = ox_make(temp % 16);
		temp /= 16;
		index--;
	}
	write(1, address, 17);
}

void			non_print_to_printable(void *addr, unsigned int size)
{
	unsigned char	temp;
	unsigned int	index;

	write(1, " ", 1);
	index = 0;
	while (index < size)
	{
		temp = *((unsigned char *)addr + index);
		if (temp >= 32 && temp <= 126)
			write(1, &temp, 1);
		else
			write(1, ".", 1);
		index++;
	}
	write(1, "\n", 1);
}

void			print_content(void *addr, unsigned int size)
{
	unsigned char	temp_c[3];
	unsigned int	index;
	unsigned char	temp;

	index = 0;
	temp_c[0] = ' ';
	while (index < 16)
	{
		if (index < size)
		{
			temp = *((unsigned char *)addr + index);
			temp_c[1] = ox_make(temp / 16 % 16);
			temp_c[2] = ox_make(temp % 16);
		}
		else
		{
			temp_c[1] = ' ';
			temp_c[2] = ' ';
		}
		if (++index % 2 == 1)
			write(1, &temp_c, 3);
		else
			write(1, &temp_c[1], 2);
	}
	non_print_to_printable(addr, size);
}

void			*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int temp;
	unsigned int index;

	index = 0;
	temp = size / 16;
	while (index < temp)
	{
		print_address((unsigned char *)addr + (16 * index));
		print_content((unsigned char *)addr + (16 * index), 16);
		index++;
	}
	temp = size % 16;
	print_address((unsigned char *)addr + size - temp);
	print_content((unsigned char *)addr + size - temp, temp);
	return (addr);
}
