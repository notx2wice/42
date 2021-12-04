/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 23:38:06 by ukim              #+#    #+#             */
/*   Updated: 2020/11/28 11:35:21 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int					ft_strlen(char *str);
int					ft_atoi(char **str);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_itoa(long long n);
char				*ft_strdup(char *str);

#endif
