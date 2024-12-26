/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:03:31 by mmad              #+#    #+#             */
/*   Updated: 2024/02/16 22:42:49 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_call_sort(t_list **stack_a, t_list **stack_b, int argc)
{
	t_list	*a;
	t_list	*b;

	a = *stack_a;
	b = *stack_b;
	if (argc == 1)
		return ;
	if (argc == 2)
		swap_2(&a);
	else if (argc == 3)
		swap_3(&a);
	else if (argc == 4)
		swap_4(&a, &b);
	else if (argc == 5)
		swap_5(&a, &b);
	else if (argc <= 100)
		ft_sort_stack(&a, &b, 15);
	else if (argc <= 500)
		ft_sort_stack(&a, &b, 35);
	else if (argc > 500)
		ft_sort_stack(&a, &b, 35);
	*stack_a = a;
}
