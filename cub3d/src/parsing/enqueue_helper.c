/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 04:06:11 by mmad              #+#    #+#             */
/*   Updated: 2024/09/26 18:39:11 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

t_queue	*fill_directions(void)
{
	t_queue	*front_direction;
	t_queue	*rear_direction;
	int		directions[4][2];
	int		i;

	front_direction = NULL;
	rear_direction = NULL;
	directions[0][0] = -1;
	directions[0][1] = 0;
	directions[1][0] = 1;
	directions[1][1] = 0;
	directions[2][0] = 0;
	directions[2][1] = -1;
	directions[3][0] = 0;
	directions[3][1] = 1;
	i = 0;
	while (i < 4)
	{
		ft_enqueue(directions[i][0], directions[i][1], &front_direction,
			&rear_direction);
		i++;
	}
	return (front_direction);
}
