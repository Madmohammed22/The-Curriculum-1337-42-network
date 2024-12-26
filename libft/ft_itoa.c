/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:14:31 by mmad              #+#    #+#             */
/*   Updated: 2023/11/21 10:27:53 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_n(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static void	reverse(char *str, int length)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
}

static char	*ft_v0(int n, int is_negative)
{
	char	*str;
	int		rem;
	int		i;

	str = malloc(sizeof(char) * ft_count_n(n) + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		is_negative = 1;
		n *= -1;
	}
	while (n != 0)
	{
		rem = n % 10;
		str[i++] = rem + 48;
		n = n / 10;
	}
	if (is_negative)
		str[i++] = '-';
	str[i] = '\0';
	reverse(str, i);
	return (str);
}

char	*ft_itoa(int n)
{
	int	is_negative;

	is_negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	return (ft_v0(n, is_negative));
}
