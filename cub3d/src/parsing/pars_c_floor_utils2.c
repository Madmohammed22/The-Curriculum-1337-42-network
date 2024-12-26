/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_c_floor_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 03:56:03 by mmad              #+#    #+#             */
/*   Updated: 2024/09/22 03:56:48 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_contain_only_digit(char *str)
{
	int	i;
	int	error;

	error = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			error = -1;
		i++;
	}
	if (error == -1)
		return (-1);
	if (ft_atoi_if(str) == false || ft_atoi(str) > 255)
		return (-1);
	return (0);
}

int	ft_may_contain_digit(char *str)
{
	int	i;
	int	faced_a_digit;

	faced_a_digit = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			faced_a_digit = 1;
		i++;
	}
	return (faced_a_digit);
}
