/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:07:08 by mmad              #+#    #+#             */
/*   Updated: 2024/01/19 14:13:51 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_lowerhex(unsigned long nb)
{
	char	*hex_digits;
	int		count;

	hex_digits = "0123456789abcdef";
	count = 0;
	if (nb > 15)
	{
		count += ft_lowerhex(nb / 16);
		count += ft_putchar(hex_digits[nb % 16]);
	}
	else
		count += ft_putchar(hex_digits[nb]);
	return (count);
}

int	ft_upperhex(unsigned int nb)
{
	char	*hex_digits;
	int		count;

	count = 0;
	hex_digits = "0123456789ABCDEF";
	if (nb > 15)
	{
		count += ft_upperhex(nb / 16);
		count += ft_putchar(hex_digits[nb % 16]);
	}
	else
		count += ft_putchar(hex_digits[nb]);
	return (count);
}
