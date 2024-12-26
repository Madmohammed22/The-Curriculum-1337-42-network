/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:03:59 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/09/17 20:49:23 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_enqueue(int x, int y, t_queue **front, t_queue **rear)
{
	t_queue	*new_node;

	new_node = (t_queue *)ft_malloc(sizeof(t_queue));
	if (!new_node)
		return ;
	new_node->x = x;
	new_node->y = y;
	new_node->next = NULL;
	if (*rear)
	{
		(*rear)->next = new_node;
		*rear = new_node;
	}
	else
	{
		*front = new_node;
		*rear = new_node;
	}
}

void	ft_dequeue(t_queue **front, t_queue **rear)
{
	t_queue	*temp;

	temp = *front;
	if (!temp)
	{
		return ;
	}
	if (*front == *rear)
	{
		*front = NULL;
		*rear = NULL;
	}
	else
	{
		*front = (*front)->next;
	}
}

bool	ft_check_up(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

void	fill_modified_map_container(t_condition *game_condition, int *i, int *j,
		t_queue **rear)
{
	int	hight;
	int	find_longest_line;

	find_longest_line = ft_find_longest_line(game_condition->map, &hight);
	while (game_condition->map[*i][*j])
	{
		if (game_condition->map[*i][*j] == ' ')
			game_condition->pure_map[*i][*j] = 'd';
		else if (game_condition->map[*i][*j] == 'B')
		{
			game_condition->pure_map[*i][*j] = '0';
			ft_enqueue(*i, *j, &game_condition->queue, rear);
		}
		else
			game_condition->pure_map[*i][*j] = game_condition->map[*i][*j];
		(*j)++;
	}
	while (*j < find_longest_line)
	{
		game_condition->pure_map[*i][*j] = 'd';
		(*j)++;
	}
}

void	fill_modified_map(t_condition *game_condition)
{
	int		i;
	int		j;
	t_queue	*rear;

	rear = NULL;
	game_condition->queue = NULL;
	game_condition->pure_map = (char **)ft_malloc(sizeof(char *)
			* (game_condition->height_of_map + 1));
	if (!game_condition->pure_map)
		return ;
	i = 0;
	while (game_condition->map[i])
	{
		game_condition->pure_map[i] = (char *)ft_malloc(sizeof(char)
				* (game_condition->width_of_map + 1));
		j = 0;
		fill_modified_map_container(game_condition, &i, &j, &rear);
		game_condition->pure_map[i][j] = '\0';
		i++;
	}
	game_condition->pure_map[i] = NULL;
}
