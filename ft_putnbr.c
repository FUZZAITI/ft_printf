/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepinhei <pepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:04:02 by pepinhei          #+#    #+#             */
/*   Updated: 2025/09/02 14:07:18 by pepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_d_i(long int n, char *base, int div)
{
	int	count;

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

int	put_nbr(int n)
{
	int					count;
	long long			nn;
	unsigned long long	mag;

	count = 0;
	nn = (long long)n;
	if (nn < 0)
	{
		count += ft_putchar('-');
		nn = (unsigned long long)(-nn);
	}
	mag = (unsigned long long)nn;
	count += putnbr_d_i(mag, "0123456789", 10);
	return (count);
}

int	put_pointer(unsigned long ptr)
{
	unsigned long long	addr;
	int					count;
	char				*base;
	unsigned long long	div;

	count = 0;
	div = 16;
	base = "0123456789abcdef";
	if (!ptr)
		return (write(1, "(nil)", 5));
	addr = (unsigned long long)ptr;
	if (addr >= div)
		count += put_pointer(addr / div);
	count += ft_putchar(base[addr % div]);
	return (count);
}

int	pre_point(void *ptr)
{
	unsigned long long		n;
	int						count;

	n = (unsigned long long)ptr;
	count = 0;
	if (ptr == 0)
		return (count += write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += (put_pointer(n));
	return (count);
}
