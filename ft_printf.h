/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepinhei <pepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:56:24 by pepinhei          #+#    #+#             */
/*   Updated: 2025/09/02 11:25:42 by pepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putstr(char *c);
int	ft_putchar(char c);
int	ft_format(char c, va_list args);
int	ft_printf(const char *format, ...);
int	putnbr_d_i(long int n, char *base, int div);
int	put_nbr(int n);
int	put_pointer(void *ptr);

#endif
