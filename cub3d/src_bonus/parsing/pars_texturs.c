/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_texturs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:30:56 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/10/01 12:20:18 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_if_file_can_open(char *str)
{
	int	fd;

	fd = open(ft_strtrim(str, " "), O_RDONLY, 0777);
	if (fd < 0)
		return (1);
	return (0);
}

int	ft_loop_on_files(t_list *node)
{
	t_list	*temp;
	int		flag;
	char	*new_str;

	temp = node;
	flag = 0;
	while (temp)
	{
		new_str = ft_strtrim((char *)temp->content, " ");
		if (check_if_file_can_open(ft_substr(new_str,
					find_specific_char(new_str, ' '), ft_strlen(new_str))) != 0
			&& !ft_strnstr(temp->content, ".xpm", ft_strlen(".xpm")))
		{
			flag = 1;
		}
		temp = temp->next;
	}
	return (flag);
}

bool	ft_pars_portion(char **substr, t_condition *condition)
{
	if (!substr)
		return (false);
	if ((ft_strncmp(substr[0], "NO", ft_strlen(substr[0])) == 0)
		|| (ft_strncmp(substr[0], "SO", ft_strlen(substr[0])) == 0)
		|| (ft_strncmp(substr[0], "EA", ft_strlen(substr[0])) == 0)
		|| (ft_strncmp(substr[0], "WE", ft_strlen(substr[0])) == 0))
	{
		condition->catch = 0;
		return (true);
	}
	else
	{
		condition->catch = 1;
		return (false);
	}
	return (true);
}

bool	ft_pars_each_node(t_list *node, t_condition *condition)
{
	t_list	*temp;
	char	**sub_str;
	char	*newstr;

	if (!node)
		return (false);
	temp = node;
	newstr = ft_strtrim((char *)temp->content, " ");
	sub_str = ft_split(newstr, ' ');
	if (ft_count_substr(sub_str) == 2)
	{
		if (ft_pars_portion(sub_str, condition) == true
			&& condition->catch == 0)
			return (true);
		else
			return (false);
	}
	else
		return (false);
	return (true);
}

bool	ft_to_do_textures(t_list *node, t_condition *condition)
{
	t_list	*temp;

	temp = node;
	while (temp)
	{
		if (ft_pars_each_node(temp, condition) == true)
			temp = temp->next;
		else
		{
			printf(RED_W "Error\nInvalid texture\n" RESET);
			return (false);
		}
	}
	if (ft_lstsize(node) != 4 || ft_duplicates(node) == false
		|| ft_loop_on_files(node) == 1)
	{
		printf(RED_W "Error\nInvalid texture\n" RESET);
		return (false);
	}
	return (true);
}
