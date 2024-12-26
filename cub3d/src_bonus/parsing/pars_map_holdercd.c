/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_holdercd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:09:12 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/09/22 04:23:57 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_map_line(char *str)
{
	char	*new_str;

	new_str = ft_strtrim(str, "1 ");
	return ((str[0] != '\n' && new_str[0] == '\n'));
}

char	**ft_create_two_dimensional_array(char **argv)
{
	int		fd;
	char	*line;
	int		flag;
	char	*str;

	flag = 0;
	str = NULL;
	fd = open(argv[1], O_CREAT | O_RDWR, 0777);
	if (fd < 0)
	{
		close(fd);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (!flag)
			flag = is_valid_map_line(line);
		str = ft_strjoin(str, line);
		if (flag && (line[0] == '\n'))
			return (NULL);
		line = get_next_line(fd);
	}
	close(fd);
	return (ft_split(str, '\n'));
}

t_list	*ft_add_substrings_to_linked_list(t_list *node, char **sub_str,
		int flag)
{
	int	i;

	if (!sub_str)
		return (NULL);
	i = 0;
	while (sub_str[i])
	{
		if (flag == 1)
			ft_lstadd_back(&node, ft_lstnew(ft_strtrim(sub_str[i], " ")));
		else
			ft_lstadd_back(&node, ft_lstnew((char *)sub_str[i]));
		i++;
	}
	return (node);
}

bool	ft_duplicates(t_list *node)
{
	int		count;
	t_list	*temp;
	t_list	*temp1;

	count = 0;
	temp = node;
	while (temp != NULL)
	{
		temp1 = node;
		count = 0;
		while (temp1 != NULL)
		{
			if (ft_strncmp(ft_strtrim(temp->content, " "),
					ft_strtrim(temp1->content, " "), 2) == 0)
			{
				count++;
			}
			temp1 = temp1->next;
		}
		if (count > 1)
			return (false);
		temp = temp->next;
	}
	return (true);
}

void	ft_print_linked_list(t_list *node)
{
	t_list	*temp;

	temp = node;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
}
