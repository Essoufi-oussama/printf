/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessoufi <oessoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:27:57 by oessoufi          #+#    #+#             */
/*   Updated: 2024/12/12 13:46:28 by oessoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putnbr(int nbr);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_putnbr_u(unsigned int nbr);
int	ft_put_hex(unsigned long num);
int	ft_put_big_hexa(unsigned int num);

#endif