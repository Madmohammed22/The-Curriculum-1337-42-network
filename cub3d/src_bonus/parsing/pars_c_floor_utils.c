/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_c_floor_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:12:05 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/09/22 04:23:06 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_count_specific_char(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

bool	ft_atoi_if(const char *nptr)
{
	int	result;

	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		if (result > 255)
			return (false);
		nptr++;
	}
	return (true);
}

bool	ft_find_color(char *str, char c)
{
	if (!str)
		return (false);
	if (ft_strrchr(str, c))
		return (true);
	return (false);
}

void	ft_import_colors(t_list *floor, t_list *ceiling, t_condition *condition)
{
	char	**floor_substr;
	char	**ceiling_substr;

	if (!floor || !ceiling)
		return ;
	floor_substr = ft_buffer_to_two_d_array(floor, ft_lstsize(floor), 0);
	ceiling_substr = ft_buffer_to_two_d_array(ceiling, ft_lstsize(ceiling), 0);
	condition->floor_color = rgb_int(ft_atoi(floor_substr[0]),
			ft_atoi(floor_substr[1]), ft_atoi(floor_substr[2]));
	condition->ceiling_color = rgb_int(ft_atoi(ceiling_substr[0]),
			ft_atoi(ceiling_substr[1]), ft_atoi(ceiling_substr[2]));
}

void	ft_node_colors(t_list *node, t_condition *condition)
{
	t_list	*floor;
	t_list	*ceiling;
	char	**f;
	char	**c;

	(void)condition;
	floor = NULL;
	ceiling = NULL;
	f = NULL;
	c = NULL;
	while (node)
	{
		if (ft_find_color(node->content, 'F') == true)
			f = ft_split(node->content + 2, ',');
		else if (ft_find_color(node->content, 'C') == true)
			c = ft_split(node->content + 2, ',');
		node = node->next;
	}
	floor = ft_add_substrings_to_linked_list(floor, f, 1);
	ceiling = ft_add_substrings_to_linked_list(ceiling, c, 1);
	ft_import_colors(floor, ceiling, condition);
}
