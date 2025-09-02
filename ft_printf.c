/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepinhei <pepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 09:39:32 by pepinhei          #+#    #+#             */
/*   Updated: 2025/09/02 13:18:02 by pepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_look(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
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
		return (put_pointer(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

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
