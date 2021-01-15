/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:06:50 by aabounak          #+#    #+#             */
/*   Updated: 2021/01/15 17:06:51 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(void)
{
	flags.width = 0;
	flags.precision = 0;
	flags.point = 0;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_count++;
}

int 	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int 	num_base(int n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

int 	ft_atoi(const char *s)
{
	long num;

	num = 0;
	while(*s >= '0' && *s <= '9')
	{
		num = num * 10 + (*s - 48);
		s++;
	}
	return (num);
}

int 	ft_isdigit(char c)
{
	if (c >= 48 && c < 58)
		return (1);
	return (0);
}

void	print_str(void)
{
	char *str;
	int  spaces;
	int precision;
	int i;

	str = va_arg(ap, char*);
	if (!str)
		str = "(null)";
	precision = (flags.point && flags.precision < ft_strlen(str)) ? flags.precision : ft_strlen(str);
	spaces = flags.width - precision;
	i = 0;
	while (spaces > 0)
	{
		ft_putchar(' ');
		spaces--;
	}
	while (i < precision)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_puthex(unsigned int n)
{
	char *num;

	num = "0123456789abcdef";
	if (n < 16)
		ft_putchar(num[n]);
	else
	{
		ft_puthex(n / 16);
		ft_puthex(n % 16);
	}
}

void	print_hex(void)
{
	unsigned int x;
	int spaces;
	int precision;
	int i;

	x = va_arg(ap, unsigned int);
	precision = (flags.precision > num_base(x, 16) ? flags.precision - num_base(x, 16) : 0);
	spaces = (precision > 0 ) ? flags.width - flags.precision : flags.width - num_base(x, 16);
	i = -1;
	while (++i < spaces)
		ft_putchar(' ');
	i = -1;
	while (++i < precision)
		ft_putchar('0');
	ft_puthex(x);
}

void	ft_putnbr(int n, int precision)
{
	unsigned int i;

	if (n < 0)
	{
		ft_putchar('-');
		while (precision)
		{
			ft_putchar('0');
			precision--;
		}
		i = -n;
	}
	else
		i = n;
	while (precision)
	{
		ft_putchar('0');
		precision--;
	}
	if (i < 10)
		ft_putchar(i + '0');
	else if (i > 9)
	{
		ft_putnbr(i / 10, precision);
		ft_putnbr(i % 10, precision);
	}
}

void	print_int(void)
{
	int d;
	int i;
	int spaces;
	int precision;
	int signe;

	d = va_arg(ap, int);
	signe = d < 0 ? 1 : 0;
	precision = (flags.precision > num_base(d, 10)) ? flags.precision - num_base(d, 10) : 0;
	spaces = (precision > 0) ? flags.width - (flags.precision + signe) : flags.width - (num_base(d, 10) + signe);
	i = -1;
	while (++i < spaces)
		ft_putchar(' ');
	ft_putnbr(d, precision);
}

void	ft_check(const char *s, int *i)
{
	if (ft_isdigit(s[*i]))
	{
		flags.width = ft_atoi(s + (*i));
		*i += num_base(flags.width, 10);
	}
	if (s[*i] == '.')
	{
		flags.point = 1;
		(*i)++;
	}
	if (ft_isdigit(s[*i]))
	{
		flags.precision = ft_atoi(s + (*i));
		*i += num_base(flags.precision, 10);
	}
	if (s[*i] == 'd')
		print_int();
	if (s[*i] == 's')
		print_str();
	else if (s[*i] == 'x')
		print_hex();
}

int		ft_printf(const char *s, ...)
{
	int i;

	g_count = 0;
	va_start(ap, s);
	i = 0;
	while (s[i])
	{
		init_flags();
		if (s[i] == '%')
		{
			i++;
			ft_check(s, &i);	
		}
		else
			ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (g_count);
}

int		main(void)
{
	ft_printf("Magic %s is %5d\n", "number", 42);
	printf("Magic %s is %5d", "number", 42);
}
