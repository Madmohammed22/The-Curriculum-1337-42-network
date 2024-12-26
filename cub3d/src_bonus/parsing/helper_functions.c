/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:17:21 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/09/22 04:20:01 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <macros.h>

void	ft_return_rotatio_angle(char c, t_condition *game_condition)
{
	if (c == 'N')
		game_condition->r_ang = NORTH_P;
	if (c == 'E')
		game_condition->r_ang = EAST_P;
	if (c == 'S')
		game_condition->r_ang = SOUTH_P;
	if (c == 'W')
		game_condition->r_ang = WEST_P;
}

void	ft_find_direction(char **new_map, int *x, int *y,
		t_condition *game_condition)
{
	int	i;
	int	j;

	i = 0;
	while (new_map[i])
	{
		j = 0;
		while (new_map[i][j])
		{
			if (new_map[i][j] == 'N' || new_map[i][j] == 'E'
				|| new_map[i][j] == 'S' || new_map[i][j] == 'W')
			{
				*x = i;
				*y = j;
				ft_return_rotatio_angle(new_map[i][j], game_condition);
				return ;
			}
			j++;
		}
		i++;
	}
}

bool	check_for_connectedness(char *str, int *n_directions)
{
	char		*new_str;
	static int	count_directions;
	int			i;

	new_str = ft_strtrim(str, " ");
	i = -1;
	while (new_str[++i])
	{
		if (new_str[i] == 'N' || new_str[i] == 'E' || new_str[i] == 'S'
			|| new_str[i] == 'W')
			count_directions++;
		if (new_str[i] != 'N' && new_str[i] != 'E' && new_str[i] != 'S'
			&& new_str[i] != 'W' && new_str[i] != ' ' && new_str[i] != '0'
			&& new_str[i] != '1')
			return (false);
	}
	*n_directions = count_directions;
	if (new_str[0] == '1' && new_str[ft_strlen(new_str) - 1] == '1')
		return (true);
	else
	{
		if (new_str[0] != '\0')
			return (false);
	}
	return (true);
}

bool	check_for_connectedness_b(char *str, int *n_directions)
{
	char		*new_str;
	static int	count_directions;
	int			i;

	new_str = ft_strtrim(str, " ");
	i = -1;
	while (new_str[++i])
	{
		if (new_str[i] == 'N' || new_str[i] == 'E' || new_str[i] == 'S'
			|| new_str[i] == 'W')
			count_directions++;
		if (new_str[i] != 'B' && new_str[i] != 'N' && new_str[i] != 'E'
			&& new_str[i] != 'S' && new_str[i] != 'W' && new_str[i] != ' '
			&& new_str[i] != '0' && new_str[i] != '1')
			return (false);
	}
	*n_directions = count_directions;
	if (new_str[0] == '1' && new_str[ft_strlen(new_str) - 1] == '1')
		return (true);
	else
	{
		if (new_str[0] != '\0')
			return (false);
	}
	return (true);
}

int	ft_check_start_end(char **map, int *n_direction, int flag)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (flag == 0)
		{
			if (check_for_connectedness(map[i], n_direction) == false)
				return (1);
		}
		else
		{
			if (check_for_connectedness_b(map[i], n_direction) == false)
				return (1);
		}
		i++;
	}
	return (0);
}
