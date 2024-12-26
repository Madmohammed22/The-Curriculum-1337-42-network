/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:12:45 by mmad              #+#    #+#             */
/*   Updated: 2024/02/11 19:36:14 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_to_stack_a(t_list **stack_a, t_list **stack_b);

void	ft_sort_stack(t_list **stack_a, t_list **stack_b, int p)
{
	t_list	*sorted_list;
	t_list	*last_index;
	int		i;

	sorted_list = ft_sort_list(ft_copy_stack(*stack_b, *stack_a));
	i = 0;
	while (i < ft_lstsize(sorted_list))
	{
		last_index = ft_lstlast(*stack_a);
		if (find(sorted_list, last_index->data) < i)
		{
			pb(&(*stack_a), &(*stack_b));
			rb(&(*stack_b));
			i++;
		}
		else if (find(sorted_list, last_index->data) <= i + p)
		{
			pb(&(*stack_a), &(*stack_b));
			i++;
		}
		else
			ra(&(*stack_a));
	}
	ft_move_to_stack_a(&(*stack_a), &(*stack_b));
	ft_lstclear(&sorted_list, del);
}

void	ft_move_to_stack_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		index;
	int		peek;

	a = *stack_a;
	b = *stack_b;
	while (ft_lstsize(b) > 0)
	{
		peek = ft_return_longest(b);
		index = find(b, peek);
		if (index < (ft_lstsize(b) / 2))
		{
			while (index-- >= 0)
				rrb(&b);
		}
		else if (index >= (ft_lstsize(b) / 2))
		{
			while (index++ < (ft_lstsize(b) - 1))
				rb(&b);
		}
		pa(&a, &b);
	}
	*stack_b = b;
	*stack_a = a;
}
