/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 03:36:47 by mmad              #+#    #+#             */
/*   Updated: 2024/09/22 03:41:34 by mmad             ###   ########.fr       */
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

int	ft_n_columns_2d(char **substr)
{
	int	i;

	i = 0;
	while (substr[i])
		i++;
	return (i);
}

void	ft_print_double_list(t_list **nodes)
{
	t_list	*temp;

	temp = *nodes;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
}
