/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Import_from_libft.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:24:47 by mmad              #+#    #+#             */
/*   Updated: 2024/06/30 17:37:36 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*nptr && *nptr == ' ') || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	sign = 1;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
	return (0);
}
