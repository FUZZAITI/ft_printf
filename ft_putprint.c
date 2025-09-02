/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepinhei <pepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:54:08 by pepinhei          #+#    #+#             */
/*   Updated: 2025/09/02 10:02:42 by pepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *c)
{
	int		i;

	if (!c)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (c[i] != '\0')
		i++;
	write(1, c, i);
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
	return (1);
}
