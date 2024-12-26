/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:18:36 by mmad              #+#    #+#             */
/*   Updated: 2024/02/11 16:39:11 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isascii(int c)
{
	if (!(c >= 0 && c <= 127))
		return (0);
	return (1);
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\t')
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_argv(int argc, char **argv)
{
	int		total_len;
	int		index;
	int		offset;
	int		counter;
	char	*arr;

	index = 1;
	counter = 0;
	total_len = 0;
	while (index < argc)
		total_len += ft_strlen(argv[index++]);
	arr = (char *)malloc(sizeof(char) * total_len + argc);
	index = 1;
	while (index < argc)
	{
		offset = 0;
		if (ft_check(argv[index]) == 1)
			return (free(arr), NULL);
		while (argv[index][offset])
			arr[counter++] = argv[index][offset++];
		arr[counter++] = ' ';
		index++;
	}
	arr[counter] = 0;
	return (arr);
}
