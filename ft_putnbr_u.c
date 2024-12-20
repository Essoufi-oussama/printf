/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessoufi <oessoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:43:07 by oessoufi          #+#    #+#             */
/*   Updated: 2024/12/11 15:28:01 by oessoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printnbr_u(int *count, unsigned int nbr)
{
	char	c;

	if (nbr == 0)
		return ;
	else
	{
		c = nbr % 10 + '0';
		ft_printnbr_u(count, nbr / 10);
		write(1, &c, 1);
		*count += 1;
	}
}

int	ft_putnbr_u(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		count++;
	}
	else
		ft_printnbr_u(&count, nbr);
	return (count);
}
