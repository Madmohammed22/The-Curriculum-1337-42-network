/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:43:34 by mmad              #+#    #+#             */
/*   Updated: 2024/02/15 16:24:57 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_one(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	ft_exit_zero(void)
{
	exit(0);
}

void	ft_call_free(char **s, int index, char *arr, void (*ft_exit)(void))
{
	while (index >= 0)
	{
		free(s[index]);
		index--;
	}
	free(s);
	free(arr);
	ft_exit();
}

int	ft_check_if_valid(char **s, struct s_handler *checker)
{
	int			result;
	int			flag;
	int			i;
	long long	value;
	int			sign;

	value = 0;
	sign = 1;
	result = 0;
	flag = 0;
	i = 0;
	while (s[i])
	{
		result = ft_atoi(s[i], checker, sign, value);
		if (result == 0)
			flag = 1;
		else if (result == 1)
		{
			flag = 0;
			break ;
		}
		i++;
	}
	checker->number2 = (int)i;
	return (flag);
}

int	ft_has_repeated_characters(char **s, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft__atoi(s[i]) == ft__atoi(s[j]))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
