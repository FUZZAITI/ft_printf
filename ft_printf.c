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

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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

static int    ft_putchar(char c)
{
    return (write(1, &c, 1));
    return (1);
}

int putnbr_d_i(long int n)
{
  int count;
   
  count = 0; 
  if (n < 0)
  {
    count += ft_putchar('-');
    n *= -1;
  }
  if (n >= 10)
    count += putnbr_d_i(n / 10);   
  count += ft_putchar((n % 10) + '0');
  return count;
}

int putnbr_u_x_X(long int n, char *base, int div)
{ 
  unsigned int hexa;
  int count;
  
  count = 0;
  hexa = (unsigned int)n; 
  if (hexa >= div)
    count += putnbr_u_x_X((hexa / div), base, div); 
  count += ft_putchar(base[hexa % div]);
  return (count);
}

int ft_format(char c, va_list args)
{
    if (c == 'c')
        return ft_putchar(va_arg(args, int));
    else if (c == 's')
        return ft_putstr(va_arg(args, char *));
    else if (c == '%')
        return ft_putchar('%');
    else if (c == 'd' || c == 'i')
        return putnbr_d_i(va_arg(args, int));
    else if (c == 'x')
        return hexa(va_arg(args, int), "0123456789abcdef", 16);
    else if (c == 'X')
        return hexa(va_arg(args, int), "0123456789ABCDEF", 16);
    else if (c == 'u')
        return hexa(va_arg(args, unsigned int), "0123456789", 10);
    return (0);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int count;

    count = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            count += ft_format(*format, args);
        }
        else
            count += ft_putchar(*format);
        format++;
    }
    va_end(args);
    return (count);
}

int    main(void)
{
    int x = 0;
    int y = 0;
    
    x = ft_printf("%s %d \n","oi", -2555);
    y = printf("%s %i \n","oi", -2555);
    return (0);
}
