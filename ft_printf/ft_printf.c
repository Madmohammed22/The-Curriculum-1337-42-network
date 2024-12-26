/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:37:27 by mmad              #+#    #+#             */
/*   Updated: 2023/12/03 09:43:04 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			else
				count += ft_call_f(format[++i], args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
