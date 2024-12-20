/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessoufi <oessoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:26:41 by oessoufi          #+#    #+#             */
/*   Updated: 2024/12/20 14:42:40 by oessoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_next(va_list *args, int *count, const char *str)
{
	if (*str == 'd' || *str == 'i')
		*count += ft_putnbr(va_arg(*args, int));
	else if (*str == 's')
		*count += ft_putstr(va_arg(*args, char *));
	else if (*str == '%')
		*count += write(1, "%", 1);
	else if (*str == 'c')
		*count += ft_putchar(va_arg(*args, int));
	else if (*str == 'u')
		*count += ft_putnbr_u(va_arg(*args, unsigned int));
	else if (*str == 'x')
		*count += ft_put_hex(va_arg(*args, unsigned int));
	else if (*str == 'X')
		*count += ft_put_big_hexa(va_arg(*args, unsigned int));
	else if (*str == 'p')
	{
		write(1, "0x", 2);
		*count += 2;
		*count += ft_put_hex(va_arg(*args, unsigned long));
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
			check_next(&args, &count, ++str);
		else
		{
			write(1, str, 1);
			count++;
		}
		if (*str)
			str++;
	}
	va_end(args);
	return (count);
}
