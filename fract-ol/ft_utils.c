/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:03:04 by mmad              #+#    #+#             */
/*   Updated: 2024/03/21 22:29:20 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_int(char *argv)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 1)
			flag = 1;
		else
			return (0);
		i++;
	}
	if (flag == 1)
		return (1);
	return (0);
}

double	ft_atod(char *str)
{
	long	integer;
	double	floating_numbr;
	double	pow;
	int		sign;

	integer = 0;
	floating_numbr = 0;
	sign = 1;
	pow = 1;
	while ((*str >= 9 && *str <= 13) || 32 == *str)
		++str;
	while ('+' == *str || '-' == *str)
		if ('-' == *str++)
			sign = -sign;
	while (*str != '.' && *str)
		integer = (integer * 10) + (*str++ - 48);
	if ('.' == *str)
		++str;
	while (*str)
	{
		pow = pow / 10;
		floating_numbr = floating_numbr + (*str++ - 48) * pow;
	}
	return ((integer + floating_numbr) * sign);
}

int	ft_first_half(const char **strr, int i, int *dotCount, int *digitCount)
{
	const char	*str = *strr;

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		(*digitCount)++;
		i++;
	}
	while (str[i] == '.')
	{
		(*dotCount)++;
		i++;
	}
	*strr = str;
	return (i);
}

int	is_float(const char *str)
{
	int	dotcount;
	int	digitcount;
	int	i;

	dotcount = 0;
	digitcount = 0;
	i = 0;
	i = ft_first_half(&str, i, &dotcount, &digitcount);
	while (str[i] >= '0' && str[i] <= '9')
	{
		digitcount++;
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		digitcount++;
		i++;
	}
	return (str[i] == '\0' && digitcount > 0 && dotcount == 1);
}
