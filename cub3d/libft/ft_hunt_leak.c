/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hunt_leak.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammedmad <mohammedmad@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:15:57 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/09/05 13:16:13 by mohammedmad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_push(void)
{
	static t_list	p;

	return (&p);
}

void	ft_hunt_leak(void)
{
	int		i;
	t_list	*head;
	t_list	*node;

	head = ft_push();
	i = 0;
	while (head)
	{
		node = head->next;
		free(head->content);
		if (i)
			free(head);
		i++;
		head = node;
	}
}

t_list	*ft_lstnew_for(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	*ft_malloc(size_t n)
{
	t_list	*head;
	void	*buffer;
	t_list	*new;

	head = ft_push();
	buffer = malloc(n);
	new = ft_lstnew_for(buffer);
	ft_lstadd_back(&head, new);
	return (buffer);
}
