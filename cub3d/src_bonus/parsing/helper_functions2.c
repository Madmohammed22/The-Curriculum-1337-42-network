/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 04:19:05 by mmad              #+#    #+#             */
/*   Updated: 2024/09/22 04:20:23 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_find_longest_line(char **substr, int *hight)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (substr[i])
	{
		if ((int)ft_strlen(substr[i]) > length)
			length = ft_strlen(substr[i]);
		i++;
	}
	*hight = i;
	return (length);
}
