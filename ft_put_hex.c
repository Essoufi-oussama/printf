/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessoufi <oessoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:47:31 by oessoufi          #+#    #+#             */
/*   Updated: 2024/12/11 15:26:50 by oessoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_hex(int *count, unsigned long num)
{
	char	*base;
	char	c;

	base = "0123456789abcdef";
	if (num > 0)
	{
		c = base[num % 16];
		ft_print_hex(count, num / 16);
		write(1, &c, 1);
		*count += 1;
	}
}

int	ft_put_hex(unsigned long num)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		count++;
	}
	else
		ft_print_hex(&count, num);
	return (count);
}
