/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_holdercd_cont.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 03:41:14 by mmad              #+#    #+#             */
/*   Updated: 2024/09/22 03:45:12 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_buffer_to_two_d_array(t_list *node, int length, int flag)
{
	int		i;
	char	**sub_str;
	char	*new_substr;

	sub_str = (char **)ft_malloc(sizeof(char *) * (length + 1));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (node)
	{
		if (flag == 0)
			sub_str[i] = ft_strdup(node->content);
		else
		{
			new_substr = ft_strtrim(node->content, " ");
			new_substr = new_substr + find_specific_char(new_substr, ' ');
			sub_str[i] = ft_strdup(ft_strtrim(new_substr, " "));
		}
		if (!sub_str[i])
			return (NULL);
		i++;
		node = node->next;
	}
	sub_str[i] = NULL;
	return (sub_str);
}

int	find_specific_char(char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

void	ft_print_substr(char **substr)
{
	int	i;

	if (!substr)
		return ;
	i = 0;
	while (substr[i])
	{
		printf("[%s]\n", substr[i]);
		i++;
	}
}

int	ft_count_substr(char **substr)
{
	int	i;

	i = 0;
	while (substr[i])
		i++;
	return (i);
}
