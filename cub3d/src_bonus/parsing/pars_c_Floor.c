/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_c_Floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:34:10 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/10/01 12:20:18 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_now_valid(char *str)
{
	int	i;
	int	start;
	int	digit;

	i = 1;
	start = i;
	digit = 0;
	while (str[i])
	{
		if (str[i] == ',' || !str[i + 1])
		{
			while (start <= i)
			{
				if (ft_isdigit(str[start]) == 1 && str[start] != ',')
				{
					digit++;
					start = i;
					break ;
				}
				start++;
			}
		}
		i++;
	}
	return (digit);
}

bool	ft_track_comma(char *str)
{
	int		i;
	int		flag;
	char	**substr;

	flag = 0;
	i = 0;
	if (ft_count_specific_char(str, ',') == 2)
	{
		if (is_now_valid(ft_strtrim(str, " ")) != 3)
			return (false);
		substr = ft_split(ft_substr(ft_strtrim(str, " "),
					find_specific_char(str, ' ') + 1, ft_strlen(str)), ',');
		while (substr[i])
		{
			if (ft_contain_only_digit(ft_strtrim(substr[i], " ")) == -1)
				flag = -1;
			i++;
		}
	}
	else
		return (false);
	if (flag == -1)
		return (false);
	return (true);
}

bool	ft_pars_colors(t_list *node)
{
	t_list	*temp;

	if (!node)
		return (false);
	temp = node;
	while (temp)
	{
		if (ft_track_comma(temp->content) == true)
			temp = temp->next;
		else
			return (false);
	}
	return (true);
}

bool	ft_spin(const char *str)
{
	size_t	str_len;
	char	**substr;

	if (!str)
		return (false);
	substr = ft_split(ft_strtrim(str, " "), ' ');
	if (!substr)
		return (false);
	str_len = ft_strlen(str);
	return (ft_strncmp(substr[0], "C", str_len) == 0 || ft_strncmp(substr[0],
			"F", str_len) == 0);
}

bool	ft_to_do_c_floor(t_list *node, t_condition *condition)
{
	t_list	*temp;

	(void)condition;
	temp = node;
	while (temp)
	{
		if (ft_spin((char *)temp->content) == true)
			temp = temp->next;
		else
		{
			printf(RED_W "Error\nInvalid Floor Celling\n" RESET);
			return (false);
		}
	}
	if (ft_lstsize(node) != 2 || ft_duplicates(node) == false
		|| ft_pars_colors(node) == false)
	{
		printf(RED_W "Error\nInvalid Floor Celling\n" RESET);
		return (false);
	}
	ft_node_colors(node, condition);
	return (true);
}
