/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:31:39 by mmad              #+#    #+#             */
/*   Updated: 2024/01/19 14:13:46 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_call_f(char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == '%')
		count += ft_putchar('%');
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		count += ft_putunsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		count += ft_lowerhex(va_arg(args, unsigned int));
	else if (format == 'X')
		count += ft_upperhex(va_arg(args, unsigned int));
	else if (format == 'p')
		count += ft_address(va_arg(args, void *));
	return (count);
}
