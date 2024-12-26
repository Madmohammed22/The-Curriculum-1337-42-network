/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:24:23 by mmad              #+#    #+#             */
/*   Updated: 2024/01/19 14:13:41 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_address(void *add)
{
	int	count;

	count = 0;
	if (add == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += ft_putstr("0x");
	count += ft_lowerhex((unsigned long)add);
	return (count);
}
