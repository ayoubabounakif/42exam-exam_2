/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:06:55 by aabounak          #+#    #+#             */
/*   Updated: 2021/01/15 17:06:56 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_flags
{
	int		width;
	int		point;
	int		precision;
}				t_flags;

t_flags			flags;
va_list			ap;
int				g_count = 0;

int		ft_printf(const char *s, ...);
void	init_flags(void);
void	ft_check(const char *s, int *i);
void	ft_putchar(char c);
int 	ft_strlen(char *s);
int 	ft_isdigit(char c);
int 	num_base(int n, int base);
int 	ft_atoi(const char *s);
void	print_int(void);
void	ft_putnbr(int n, int precision);
void	print_str(void);
void	print_hex(void);
void	ft_puthex(unsigned int n);
#endif