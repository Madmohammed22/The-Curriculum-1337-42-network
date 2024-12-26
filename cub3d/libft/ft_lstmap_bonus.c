/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:07:47 by mmad              #+#    #+#             */
/*   Updated: 2023/11/22 20:29:58 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*next;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			while (new_lst)
			{
				next = new_lst->next;
				del(new_lst->content);
				free(new_lst);
				new_lst = next;
			}
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
