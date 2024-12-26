/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammedmad <mohammedmad@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:02:40 by mmad              #+#    #+#             */
/*   Updated: 2024/09/05 13:15:08 by mohammedmad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
