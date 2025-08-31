#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int    ft_putstr(char *c);
int    ft_putchar(char c);
int putnbr_d_i(long int n, char *base, int div);
int ft_format(char c, va_list args);
int ft_printf(const char *format, ...);

#endif
