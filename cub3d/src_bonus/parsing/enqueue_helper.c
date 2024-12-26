/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 04:01:26 by mmad              #+#    #+#             */
/*   Updated: 2024/09/26 22:30:40 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_n_columns_2d(char **substr)
{
	int	i;

	i = 0;
	while (substr[i])
		i++;
	return (i);
}

void	scale_size_of_map(t_condition *condition, int *new_hight,
		int *new_width)
{
	condition->width_padding = 0;
	condition->hight_padding = 0;
	if (condition->height_of_map > 9)
		*new_hight = condition->height_of_map;
	else
	{
		condition->hight_padding = (9 - condition->height_of_map) / 2;
		*new_hight = 9;
	}
	if (condition->width_of_map > 9)
		*new_width = condition->width_of_map;
	else
	{
		condition->width_padding = (9 - condition->width_of_map) / 2;
		*new_width = 9;
	}
}

bool	valid(t_condition *condition, int x, int y)
{
	return (y - condition->hight_padding >= 0 && x
		- condition->width_padding >= 0 && y
		- condition->hight_padding < condition->height_of_map && x
		- condition->width_padding < condition->width_of_map);
}

void	ft_costom_map(t_condition *cnd)
{
	char	**new_pure_map;

	int (new_width), (new_hight), (x), (y);
	scale_size_of_map(cnd, &new_hight, &new_width);
	new_pure_map = (char **)ft_malloc(sizeof(char *) * (new_hight + 1));
	y = -1;
	while (++y < new_hight)
	{
		new_pure_map[y] = (char *)ft_malloc(sizeof(char) * new_width + 1);
		x = -1;
		while (++x < new_width)
		{
			if (valid(cnd, x, y))
				new_pure_map[y][x] = cnd->pure_map[y - cnd->hight_padding][x
					- cnd->width_padding];
			else
				new_pure_map[y][x] = 'd';
		}
		new_pure_map[y][x] = '\0';
	}
	new_pure_map[y] = NULL;
	cnd->pure_map = new_pure_map;
	cnd->width_of_map = new_width;
	cnd->height_of_map = new_hight;
	ft_find_direction(cnd->pure_map, &cnd->y_player, &cnd->x_player, cnd);
}
