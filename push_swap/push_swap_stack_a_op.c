/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_a_op.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:43:47 by mmad              #+#    #+#             */
/*   Updated: 2024/02/14 09:39:04 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a)
{
	t_list	*temp;
	t_list	*prev;
	t_list	*before_prev;
	t_list	*save;

	if (!(*stack_a) || !((*stack_a)->next))
		return ;
	temp = *stack_a;
	prev = NULL;
	while (temp->next)
	{
		before_prev = prev;
		prev = temp;
		temp = temp->next;
	}
	save = prev;
	prev = prev->next;
	prev->next = save;
	save->next = NULL;
	if (before_prev != NULL)
		before_prev->next = prev;
	else
		*stack_a = prev;
	ft_putendl_fd("sa", 1);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*last_stack_b;
	t_list	*temp;
	t_list	*prev_last;

	if (!(*stack_b))
		return ;
	last_stack_b = ft_lstlast(*stack_b);
	if (!last_stack_b)
		return ;
	ft_lstadd_back(stack_a, last_stack_b);
	temp = *stack_b;
	prev_last = NULL;
	while (temp->next)
	{
		prev_last = temp;
		temp = temp->next;
	}
	if (prev_last)
		prev_last->next = NULL;
	else
		*stack_b = NULL;
	ft_putendl_fd("pa", 1);
}

void	ra(t_list **stack_a)
{
	t_list	*get_last;
	t_list	*temp;

	get_last = ft_lstlast(*stack_a);
	temp = *stack_a;
	while (temp)
	{
		if (temp->next->data == get_last->data)
			break ;
		temp = temp->next;
	}
	temp->next = NULL;
	temp = *stack_a;
	ft_lstadd_front(&(*stack_a), get_last);
	ft_putendl_fd("ra", 1);
}

void	rra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*save_head;

	temp = *stack_a;
	save_head = temp;
	temp = temp->next;
	*stack_a = temp;
	save_head->next = NULL;
	ft_lstadd_back(&(*stack_a), save_head);
	ft_putendl_fd("rra", 1);
}
