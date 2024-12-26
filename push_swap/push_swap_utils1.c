/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:48:13 by mmad              #+#    #+#             */
/*   Updated: 2024/02/17 18:17:18 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_ptr;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	temp_ptr = *lst;
	while (temp_ptr->next != NULL)
		temp_ptr = temp_ptr->next;
	temp_ptr->next = new;
}

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		count_node;

	temp = lst;
	count_node = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count_node++;
	}
	return (count_node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !*lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
