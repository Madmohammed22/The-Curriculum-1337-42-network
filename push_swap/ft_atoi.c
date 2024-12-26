/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:16:52 by mmad              #+#    #+#             */
/*   Updated: 2024/02/20 20:47:58 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cont(const char **ptr, int sign)
{
	const char	*nptr;

	nptr = *ptr;
	while ((*nptr && *nptr == ' ') || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if ((*nptr == '+' || *nptr == '-') && *(nptr + 1) != '\0')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	*ptr = nptr;
	return (sign);
}

int	ft_atoi(const char *nptr, struct s_handler *result, int sign,
		long long value)
{
	long long	result_value;

	sign = cont(&nptr, sign);
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (value * 10 > INT_MAX)
			return (1);
		value = value * 10 + (*nptr - '0');
		nptr++;
	}
	if (*nptr == '\0')
	{
		result_value = sign * value;
		if (result_value > INT_MAX || result_value < INT_MIN)
			return (1);
		result->number = (int)result_value;
	}
	else
		return (1);
	return (0);
}
