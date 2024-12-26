/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:48:21 by mmad              #+#    #+#             */
/*   Updated: 2024/01/19 14:14:08 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putunsigned(n / 10);
		count += ft_putunsigned(n % 10);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}
