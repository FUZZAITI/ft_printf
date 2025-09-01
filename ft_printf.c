/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepinhei <pepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 09:39:32 by pepinhei          #+#    #+#             */
/*   Updated: 2025/08/16 16:17:19 by pepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <unistd.h>

int    ft_putstr(char *c);
int    ft_putchar(char c);
int ft_format(char c, va_list args);
int ft_printf(const char *format, ...);
int putnbr_d_i(long int n, char *base, int div);
int put_nbr(int n);
int put_pointer(void *ptr);

int    ft_putstr(char *c)
{
	int        i;
	if (!c)
	{
	   write(1,"(null)",6);
		   return (6);
	}
	i = 0;
	while (c[i] != '\0')
	  i++;
	write(1, c, i);
	return (i);
}

int    ft_putchar(char c)
{
	return (write(1, &c, 1));
	return (1);
}

int ft_look(char c, va_list args)
{
	if (c == 'c')
		return ft_putchar(va_arg(args, int));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'd' || c == 'i')
		return (put_nbr(va_arg(args, int)));
	else if (c == 'x')
		return (putnbr_d_i(va_arg(args, unsigned int), "0123456789abcdef", 16));
	else if (c == 'X')
		return (putnbr_d_i(va_arg(args, unsigned int), "0123456789ABCDEF", 16));
	else if (c == 'u')
		return (putnbr_d_i(va_arg(args, unsigned int), "0123456789", 10));
	else if (c == 'p')
	  return put_pointer(va_arg(args, void *));
	return (0);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_look(*format, args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}

int putnbr_d_i(long int n, char *base, int div)
{
  int count;
   
  count = 0; 
  if (n < 0)
  {
	count += ft_putchar('-');
	n *= -1;
  }
  if (n >= div)
	count += putnbr_d_i((n / div), base, div); 
  count += ft_putchar(base[n % div]);
  return (count);
}

int put_nbr(int n)
{
	int count = 0;
	long long nn = (long long)n;                 
	unsigned long long mag;

	if (nn < 0)
	{
		count += ft_putchar('-');
		nn = (unsigned long long)(-nn);
	}
	mag = (unsigned long long)nn;

	count += putnbr_d_i(mag, "0123456789", 10);
	return count;
}

int put_pointer(void *ptr)
{
	int count;

	count = 0;
	if (!ptr)
		return (count += write(1, "(nil)", 5));

	count += write(1, "0x", 2);
	count += putnbr_d_i((unsigned long)ptr,"0123456789abcdef", 16);
	return count;
}


int main(void)
{
  int a = -2147483648;
  unsigned int u = 4294967295u;
  
	void *p = &a;
//    int x = printf("%c %s %p %p %d %i %u %u %x %X %% \n", '4', "42", p, (void*)0, 'p', 42, -42, 42, 42, -42);
	int y = ft_printf("%c %s %p %p %d %i %u %u %x %X %% \n", '4', "42", p, (void*)0, 'p', 42, -42, 42, 42, -42);
//    printf("%d\n",x);
	ft_printf("%d\n",y);

	return 0;
}
