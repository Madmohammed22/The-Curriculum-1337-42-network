/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_b_op_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:47:36 by mmad              #+#    #+#             */
/*   Updated: 2024/02/17 20:10:59 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	b_sb(t_list **stack_b)
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
}

void	b_pb(t_list **stack_a, t_list **stack_b)
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
}

void	b_rb(t_list **stack_b)
{
	t_list	*get_last;
	t_list	*temp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	get_last = ft_lstlast(*stack_b);
	temp = *stack_b;
	while (temp->next)
	{
		if (temp->next->data == get_last->data)
			break ;
		temp = temp->next;
	}
	temp->next = NULL;
	temp = *stack_b;
	ft_lstadd_front(&(*stack_b), get_last);
}

void	b_rrb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*save_head;

	if (!(*stack_b))
		return ;
	temp = *stack_b;
	save_head = temp;
	temp = temp->next;
	*stack_b = temp;
	save_head->next = NULL;
	ft_lstadd_back(&(*stack_b), save_head);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	b_rra(&(*stack_a));
	b_rrb(&(*stack_b));
}
