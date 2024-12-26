/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_for_each.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 03:52:24 by mmad              #+#    #+#             */
/*   Updated: 2024/09/26 18:40:49 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	process_c_flor(char *str)
{
	char	*trimmed_str;

	trimmed_str = ft_strtrim(str, " ");
	if ((trimmed_str[0] == 'F' && trimmed_str[1] == ' ')
		|| (trimmed_str[0] == 'C' && trimmed_str[1] == ' '))
	{
		return (true);
	}
	return (false);
}

bool	process_textture(char *str)
{
	char	*trimmed_str;

	trimmed_str = ft_strtrim(str, " ");
	if ((trimmed_str[0] == 'N' && trimmed_str[1] == 'O'
			&& trimmed_str[2] == ' ') || (trimmed_str[0] == 'E'
			&& trimmed_str[1] == 'A' && trimmed_str[2] == ' ')
		|| (trimmed_str[0] == 'S' && trimmed_str[1] == 'O'
			&& trimmed_str[2] == ' ') || (trimmed_str[0] == 'W'
			&& trimmed_str[1] == 'E' && trimmed_str[2] == ' '))
	{
		return (true);
	}
	return (false);
}

void	ft_process_game_condition(t_list *textures, t_list *c_flor, t_list *map,
		t_condition *game_condition)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (game_condition->substr[i])
	{
		if (!flag && !ft_strtrim(game_condition->substr[i], " 1")[0])
			flag = 1;
		if (process_c_flor(game_condition->substr[i]) == true && !flag)
			ft_lstadd_back(&c_flor,
				ft_lstnew(ft_strdup((char *)game_condition->substr[i])));
		else if (process_textture(game_condition->substr[i]) == true && !flag)
			ft_lstadd_back(&textures,
				ft_lstnew(ft_strdup((char *)game_condition->substr[i])));
		else
			ft_lstadd_back(&map,
				ft_lstnew(ft_strdup((char *)game_condition->substr[i])));
		i++;
	}
	game_condition->textures = ft_buffer_to_two_d_array(textures,
			ft_lstsize(textures), 0);
	game_condition->c_flor = ft_buffer_to_two_d_array(c_flor,
			ft_lstsize(c_flor), 0);
	game_condition->map = ft_buffer_to_two_d_array(map, ft_lstsize(map), 0);
}

bool	ft_grep_to_pars_if(char ch, t_condition *condition, bool (*f)(t_list *,
			t_condition *condition))
{
	t_list *(textures), *(c_flor), *(map);
	textures = NULL;
	c_flor = NULL;
	map = NULL;
	ft_process_game_condition(textures, c_flor, map, condition);
	condition->width_of_map = ft_find_longest_line(condition->map,
			&condition->height_of_map);
	textures = ft_add_substrings_to_linked_list(textures, condition->textures,
			0);
	condition->pure_texture = ft_buffer_to_two_d_array(textures,
			ft_lstsize(textures), 1);
	fill_modified_map(condition);
	ft_find_direction(condition->pure_map, &condition->y_player,
		&condition->x_player, condition);
	c_flor = ft_add_substrings_to_linked_list(c_flor, condition->c_flor, 0);
	if (ch == '.')
		return (f(textures, condition));
	else if (ch == ',')
		return (f(c_flor, condition));
	else
	{
		if (f(map, condition) != true)
			return (false);
	}
	return (true);
}
