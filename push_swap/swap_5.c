/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:17:20 by mmad              #+#    #+#             */
/*   Updated: 2024/02/11 20:04:34 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_5(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		lowest;

	a = *stack_a;
	b = *stack_b;
	i = 0;
	lowest = ft_return_lowest(a);
	while (i < 5)
	{
		if (ft_lstlast(a)->data == lowest)
			break ;
		if (find(a, lowest) <= 2)
			rra(&a);
		else
			ra(&a);
		i++;
	}
	pb(&a, &b);
	swap_4(&a, &b);
	pa(&a, &b);
	*stack_a = a;
}
