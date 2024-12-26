/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:28:24 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/10/01 12:20:18 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_if_d(char **new_map, t_queue *front, int *x, int *y)
{
	*x = front->x;
	*y = front->y;
	if (!*x || new_map[*x - 1][*y] == 'd' || new_map[*x][*y - 1] == 'd'
		|| new_map[*x][*y + 1] == 'd' || new_map[*x + 1][*y] == 'd')
	{
		return (false);
	}
	return (true);
}

bool	bfs_main_loop(char **new_map, t_queue **front, t_queue **rear)
{
	t_queue	*direction;

	direction = fill_directions();
	int (nx), (ny), (x), (y);
	while (*front)
	{
		if (!ft_check_if_d(new_map, *front, &x, &y))
			return (false);
		while (direction)
		{
			nx = x + direction->x;
			ny = y + direction->y;
			if (nx >= 0 && ny >= 0 && new_map[nx][ny] == '0')
			{
				new_map[nx][ny] = '1';
				ft_enqueue(nx, ny, front, rear);
			}
			direction = direction->next;
		}
		new_map[x][y] = '1';
		ft_dequeue(front, rear);
	}
	return (true);
}

bool	check_for_dead_ends(char **new_map)
{
	int	i;
	int	j;

	i = 0;
	while (new_map[++i])
	{
		j = -1;
		while (new_map[i][++j])
		{
			if (new_map[i][j] == 'd')
			{
				if ((new_map[i - 1] && new_map[i - 1][j] == '0') || (new_map[i
						+ 1] && new_map[i + 1][j] == '0') || (new_map[i][j + 1]
						&& new_map[i][j + 1] == '0') || (j > 0 && new_map[i][j
						- 1] && new_map[i][j - 1] == '0'))
					return (false);
			}
			if (new_map[i][j] == '0')
			{
				if ((new_map[i - 1] && new_map[i - 1][j] == 'd'))
					return (false);
			}
		}
	}
	return (true);
}

bool	check_if_wall_can_exist(char **new_map)
{
	int	i;
	int	j;

	i = 0;
	while (new_map[++i])
	{
		j = -1;
		while (new_map[i][++j])
		{
			if (new_map[i][j] == 'B')
			{
				if ((new_map[i - 1] && new_map[i - 1][j] == 'd') || (new_map[i
						+ 1] && new_map[i + 1][j] == 'd') || (new_map[i][j + 1]
						&& new_map[i][j + 1] == '0') || (j > 0 && new_map[i][j
						- 1] && new_map[i][j - 1] == '0'))
				{
					return (false);
				}
			}
		}
	}
	return (true);
}

bool	ft_to_do_map(t_list *node, t_condition *game_condition)
{
	int		n_direction;
	t_list	*new_map;

	new_map = NULL;
	(void)node;
	if (!game_condition->map)
		return (printf(RED_W "Error\nInvalid Map\n" RESET), false);
	fill_modified_map(game_condition);
	if (ft_check_up(game_condition->map[0]) == false
		|| ft_check_up(game_condition->map[ft_n_columns_2d(game_condition->map)
				- 1]) == false)
		return (printf(RED_W "Error\nInvalid Map\n" RESET), false);
	if (!(ft_check_start_end(game_condition->map, &n_direction, 0) == 0
			&& n_direction == 1))
		return (printf(RED_W "Error\nInvalid Map\n" RESET), false);
	new_map = ft_add_substrings_to_linked_list(new_map,
			game_condition->pure_map, 0);
	if (breadth_first_search(ft_buffer_to_two_d_array(new_map,
				ft_lstsize(new_map), 0), game_condition)
		&& check_for_dead_ends(game_condition->pure_map))
		return (true);
	return (printf(RED_W "Error\nGap Exist\n" RESET), false);
}
