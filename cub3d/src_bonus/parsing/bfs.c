/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:28:24 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/09/26 19:56:03 by mmad             ###   ########.fr       */
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

bool	breadth_first_search(char **new_map, t_condition *game_condition)
{
	t_queue *(front), *(rear);
	int (x), (y);
	front = NULL;
	rear = NULL;
	ft_find_direction(new_map, &x, &y, game_condition);
	ft_enqueue(x, y, &front, &rear);
	return (bfs_main_loop(new_map, &front, &rear));
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
					return (false);
			}
		}
	}
	return (true);
}
