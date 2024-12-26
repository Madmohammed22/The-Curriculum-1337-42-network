/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:39:20 by mmad              #+#    #+#             */
/*   Updated: 2024/02/11 20:04:08 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_4(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		lowest;

	a = *stack_a;
	b = *stack_b;
	i = 0;
	lowest = ft_return_lowest(a);
	while (i < 4)
	{
		if (ft_lstlast(a)->data == lowest)
			break ;
		if (find(a, lowest) < 2)
			rra(&a);
		else
			ra(&a);
		i++;
	}
	pb(&a, &b);
	swap_3(&a);
	pa(&a, &b);
	*stack_a = a;
}
