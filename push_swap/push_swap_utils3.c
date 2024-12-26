/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:26:04 by mmad              #+#    #+#             */
/*   Updated: 2024/02/17 20:12:43 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_linked_stack(t_list **stack, int value)
{
	t_list	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return ;
	new_node->data = value;
	if (!(*stack))
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		*stack = new_node;
	}
}

void	del(t_list *data)
{
	free(data);
}

void	ft_lstclear(t_list **lst, void (*del)(t_list *))
{
	t_list	*next;
	t_list	*temp;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		next = temp->next;
		(del)(temp);
		temp = next;
	}
	*lst = NULL;
}

t_list	*ft_copy_stack(t_list *stack_b, t_list *stack_a)
{
	t_list	*new_node;

	if (!stack_a)
		return (NULL);
	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->data = (stack_a)->data;
	new_node->next = ft_copy_stack(stack_b, ((stack_a)->next));
	return (new_node);
}

int	ft_check_if_sorted(t_list **stack_a)
{
	int		flag;
	t_list	*temp;

	if (!(*stack_a))
		return (0);
	flag = 0;
	temp = *stack_a;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			flag = 1;
		else
		{
			flag = 0;
			break ;
		}
		temp = temp->next;
	}
	return (flag);
}
