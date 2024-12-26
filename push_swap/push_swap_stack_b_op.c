/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_b_op.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:46:39 by mmad              #+#    #+#             */
/*   Updated: 2024/02/10 11:21:25 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*prev;
	t_list	*before_prev;
	t_list	*save;

	if (!(*stack_b) || !((*stack_b)->next))
		return ;
	temp = *stack_b;
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
		*stack_b = prev;
	ft_putendl_fd("sb", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*last_stack_a;
	t_list	*temp;
	t_list	*prev_last;

	if (!(*stack_a))
		return ;
	last_stack_a = ft_lstlast(*stack_a);
	if (!last_stack_a)
		return ;
	ft_lstadd_back(stack_b, last_stack_a);
	temp = *stack_a;
	prev_last = NULL;
	while (temp->next)
	{
		prev_last = temp;
		temp = temp->next;
	}
	if (prev_last)
		prev_last->next = NULL;
	else
		*stack_a = NULL;
	ft_putendl_fd("pb", 1);
}

void	rb(t_list **stack_b)
{
	t_list	*get_last;
	t_list	*temp;

	get_last = ft_lstlast(*stack_b);
	temp = *stack_b;
	while (temp)
	{
		if (temp->next->data == get_last->data)
			break ;
		temp = temp->next;
	}
	temp->next = NULL;
	temp = *stack_b;
	ft_lstadd_front(&(*stack_b), get_last);
	ft_putendl_fd("rb", 1);
}

void	rrb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*save_head;

	temp = *stack_b;
	save_head = temp;
	temp = temp->next;
	*stack_b = temp;
	save_head->next = NULL;
	ft_lstadd_back(&(*stack_b), save_head);
	ft_putendl_fd("rrb", 1);
}
