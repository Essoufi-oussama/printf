/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_big_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessoufi <oessoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:59:41 by oessoufi          #+#    #+#             */
/*   Updated: 2024/12/11 15:25:32 by oessoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_hex(int *count, unsigned int num)
{
	char	*base;
	char	c;

	base = "0123456789ABCDEF";
	if (num > 0)
	{
		c = base[num % 16];
		ft_print_hex(count, num / 16);
		write(1, &c, 1);
		*count += 1;
	}
}

int	ft_put_big_hexa(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		count += 1;
	}
	else
		ft_print_hex(&count, num);
	return (count);
}
