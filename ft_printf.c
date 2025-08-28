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
int    ft_putstr(char *c);
static int    ft_putchar(char c);

int    ft_putstr(char *c)
{
    int        i;

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

int putnbr_hexa(long int n, char *base, int div)
{ 
  unsigned int hexa;
  int count;
  
  count = 0;
  hexa = (unsigned int)n; 
  if (hexa >= div)
    count += putnbr_hexa((hexa / div), base, div); 
  count += ft_putchar(base[hexa % div]);
  return (count);
}

int    ft_printf(const char *format, ...)
{
    va_list    args;
    int        count;

    count = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
                count += ft_putchar(va_arg(args, int));
            else if (*format == 's')
                count += ft_putstr(va_arg(args, char *));
            else if (*format == '%')
                count += ft_putchar('%');
            else if (*format == 'd')
                count += hexa(va_arg(args, int),"0123456789",10);
            else if (*format == 'i')
                count += hexa(va_arg(args, int),"0123456789",10);
            else if (*format == 'x')
                count += hexa(va_arg(args, int),"0123456789abcdef",16);
            else
            {
                ft_putchar('%');
                format--;
            }
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
