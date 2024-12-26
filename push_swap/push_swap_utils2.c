/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:58:29 by mmad              #+#    #+#             */
/*   Updated: 2024/02/10 11:30:31 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *a, t_list *b)
{
	int	temp;

	temp = a->data;
	a->data = b->data;
	b->data = temp;
}

t_list	*ft_sort_list(t_list *stack)
{
	t_list	*i;
	t_list	*j;
	t_list	*min_index;

	i = stack;
	while (i)
	{
		min_index = i;
		j = i->next;
		while (j)
		{
			if (j->data < min_index->data)
				min_index = j;
			j = j->next;
		}
		swap(min_index, i);
		i = i->next;
	}
	return (stack);
}

int	find(t_list *head, int n)
{
	int	index;

	index = 0;
	while (head)
	{
		if ((head)->data == n)
			return (index);
		index++;
		(head) = (head)->next;
	}
	return (index);
}

int	ft_return_longest(t_list *stack)
{
	t_list	*temp;
	int		big_number;

	temp = stack;
	big_number = temp->data;
	while (temp)
	{
		if (temp->data > big_number)
			big_number = temp->data;
		temp = temp->next;
	}
	return (big_number);
}

int	ft_return_lowest(t_list *stack)
{
	t_list	*temp;
	int		min_number;

	temp = stack;
	min_number = temp->data;
	while (temp)
	{
		if (temp->data < min_number)
			min_number = temp->data;
		temp = temp->next;
	}
	return (min_number);
}
