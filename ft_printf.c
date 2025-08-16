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


static int	count(long int n);
static	void	build(long int num, char *ptr, int len);
int	ft_putstr(char *c);


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char						*ptr;
	const unsigned char					*ptrsrc;
	size_t								i;

	if (!dst && !src)
		return (0);
	ptr = (unsigned char *)dst;
	ptrsrc = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptr[i] = ptrsrc[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char		*dup;
	size_t		i;

	i = strlen(s) + 1;
	dup = malloc(i);
	if (!dup)
		return (0);
	ft_memcpy(dup, s, i);
	return (dup);
}

char	*ft_itoa(int n)
{
	int			neg;
	int			len;
	char		*ptr;
	long int	num;

	num = n;
	neg = 0;
	if (num == 0)
		return (ft_strdup("0"));
	if (num < 0)
	{
		neg = 1;
		num = -num;
	}
	len = count(num) + neg;
	ptr = malloc(len + 1);
	if (!ptr)
		return (0);
	ptr[len] = '\0';
	build(num, ptr, len);
	if (neg)
		ptr[0] = '-';
	ft_putstr(ptr);
}

static int	count(long int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	void	build(long int num, char *ptr, int len)
{
	while (num > 0)
	{
		ptr[--len] = (num % 10) + '0';
		num = num / 10;
	}
}

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
	return (1);
}

int	ft_putstr(char *c)
{
	int		i;

	i = 0;
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				ft_putchar(va_arg(args, int));
			else if (*format == 's')
				ft_putstr(va_arg(args, char *));
			else if (*format == '%')
				ft_putchar('%');
			else if (*format == 'd')
				ft_itoa(va_arg(args, int));
			else if (*format == 'i')
				ft_itoa(va_arg(args, int));							
			else
			{
				ft_putchar('%');
				format--;
			}
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}


int	main(void)
{
	ft_printf ("%s %s %s %%%% %d %i %d %i", "printou a string 1", "printou a string 2", "printou a string 3", -1, 2, 3, 4);
	return (0);
}

