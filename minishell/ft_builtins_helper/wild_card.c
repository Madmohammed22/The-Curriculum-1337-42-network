/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_card.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abquaoub <abquaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:21:59 by mmad              #+#    #+#             */
/*   Updated: 2024/05/24 18:17:36 by abquaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

int	ft_wild_card_container(char *str, char *pattern, int *s_index, int *p_index)
{
	while (str[*s_index] != '\0')
	{
		if (pattern[*p_index] != '\0' && (pattern[*p_index] == str[*s_index]))
		{
			(*s_index)++;
			(*p_index)++;
		}
		else if (pattern[*p_index] != '\0' && pattern[*p_index] == '*')
		{
			g_ptr.last_wildcard_idx = *p_index;
			g_ptr.next_to_wildcard_idx = ++(*p_index);
			g_ptr.s_backtrack_idx = *s_index;
		}
		else if (g_ptr.s_backtrack_idx == -1)
			return (0);
		else
		{
			*p_index = g_ptr.next_to_wildcard_idx;
			*s_index = ++(g_ptr.s_backtrack_idx);
		}
	}
	return (1);
}

int	ft_wild_card_string_matching(char *str, char *pattern)
{
	int	s_index;
	int	p_index;

	s_index = 0;
	p_index = 0;
	g_ptr.last_wildcard_idx = -1;
	g_ptr.s_backtrack_idx = -1;
	g_ptr.next_to_wildcard_idx = -1;
	if (!ft_wild_card_container(str, pattern, &s_index, &p_index))
		return (0);
	while (pattern[p_index] != '\0')
	{
		if (pattern[p_index] != '*')
			return (0);
		p_index++;
	}
	return (1);
}

t_list	*ft_helper_wild(char *p, DIR *dir)
{
	struct dirent	*dirptr;
	t_list			*buff;

	buff = NULL;
	dirptr = readdir(dir);
	if (!dir)
		ft_exit_status(1);
	else
	{
		dirptr = readdir(dir);
		while (dirptr)
		{
			if (!g_ptr.ff && ((char *)dirptr->d_name)[0] == '.')
				g_ptr.yy++;
			else
			{
				if (ft_wild_card_string_matching((char *)dirptr->d_name, p))
					ft_lstadd_back(&buff, ft_lstnew((char *)dirptr->d_name));
			}
			dirptr = readdir(dir);
		}
	}
	return (buff);
}

t_list	*ft_wild_card(char *p)
{
	t_list	*buff;
	DIR		*dir;

	g_ptr.ff = 0;
	g_ptr.yy = 0;
	if (p[0] == '.')
		g_ptr.ff = 1;
	while (p && p[0] == '.' && *++p == '/')
		p++;
	dir = opendir(".");
	buff = ft_helper_wild(p, dir);
	if (!buff)
		buff = ft_lstnew(p);
	closedir(dir);
	return (buff);
}

void	ft_for_wild(char *str, t_list **head)
{
	t_list	*node;

	node = NULL;
	node = ft_wild_card(str);
	if (!node)
		node = ft_lstnew(str);
	ft_lstadd_back(head, node);
}
