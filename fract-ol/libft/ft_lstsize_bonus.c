/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:14:54 by mmad              #+#    #+#             */
/*   Updated: 2023/11/18 23:40:10 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		count_node;

	temp = lst;
	count_node = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count_node++;
	}
	return (count_node);
}
