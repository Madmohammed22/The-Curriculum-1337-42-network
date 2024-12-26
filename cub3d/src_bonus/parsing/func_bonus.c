/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 04:17:08 by mmad              #+#    #+#             */
/*   Updated: 2024/10/01 12:20:18 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_to_do_map_bonus(t_list *node, t_condition *game_condition)
{
	t_list	*new_map;
	int		n_direction;

	(void)node;
	new_map = NULL;
	if (!game_condition->map)
		return (printf(RED_W "Error\nInvalid Map\n" RESET), false);
	fill_modified_map(game_condition);
	if (ft_check_up(game_condition->map[0]) == false
		|| ft_check_up(game_condition->map[ft_n_columns_2d(game_condition->map)
				- 1]) == false)
		return (printf(RED_W "Error\nInvalid Map\n" RESET), false);
	if (!(ft_check_start_end(game_condition->map, &n_direction, 1) == 0
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

bool	move_on_if_map_valid_bonus(t_condition *condition)
{
	if (condition->substr == NULL)
	{
		printf(RED_W "Error\n" RESET);
		printf(RED_W "Line in the map\n" RESET);
		ft_hunt_leak();
		return (false);
	}
	if (ft_grep_to_pars_if('.', condition, ft_to_do_textures)
		&& ft_grep_to_pars_if(',', condition, ft_to_do_c_floor)
		&& ft_grep_to_pars_if('1', condition, ft_to_do_map_bonus))
	{
		printf(GRN_W "[Valid]\n" RESET);
	}
	else
	{
		ft_hunt_leak();
		return (false);
	}
	if (condition->height_of_map < 9 || condition->width_of_map < 9)
		ft_costom_map(condition);
	return (true);
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
