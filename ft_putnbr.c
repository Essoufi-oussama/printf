/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessoufi <oessoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:12:21 by oessoufi          #+#    #+#             */
/*   Updated: 2024/12/11 15:29:31 by oessoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printnbr(int *count, int nbr)
{
	char	c;

	if (nbr == 0)
		return ;
	else
	{
		c = nbr % 10 + '0';
		ft_printnbr(count, nbr / 10);
		write(1, &c, 1);
		*count += 1;
	}
}

int	ft_putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		count += 11;
		return (count);
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
	{
		write(1, "0", 1);
		count++;
	}
	else
		ft_printnbr(&count, nbr);
	return (count);
}
