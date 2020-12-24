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

void			init_flags(void);
void			ft_putchar(char c);
void			ft_putnbr(int n, int precision);
int				ft_strlen(char *s);
int				ft_isdigit(char c);
int				ft_atoi(const char *s);
void			ft_puthex(unsigned int n);
int				num_base(int n, int base);
void			print_str(void);
void			print_int(void);
void			print_hex(void);
void			ft_check(const char *s, int *i);
int				ft_printf(const char *s, ...);
#endif
