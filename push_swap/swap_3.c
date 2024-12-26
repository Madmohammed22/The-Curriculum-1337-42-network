/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:16:34 by mmad              #+#    #+#             */
/*   Updated: 2024/02/11 15:20:58 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_3(t_list **stack_a)
{
	t_list	*temp;
	int		long_number;
	int		index;

	temp = *stack_a;
	long_number = ft_return_longest(temp);
	index = find(temp, long_number);
	if ((index == 1) && temp->data > temp->next->next->data)
	{
		rra(&temp);
		sa(&temp);
	}
	else if (index == 1)
		rra(&temp);
	if ((index == 0) && temp->next->data < temp->next->next->data)
		sa(&temp);
	if ((index == 2) && temp->data < temp->next->data)
	{
		ra(&temp);
		sa(&temp);
	}
	else if (index == 2)
		ra(&temp);
	*stack_a = temp;
}
