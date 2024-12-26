/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:48:23 by mmad              #+#    #+#             */
/*   Updated: 2023/11/23 18:32:47 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_ptr;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	temp_ptr = *lst;
	while (temp_ptr->next != NULL)
		temp_ptr = temp_ptr->next;
	temp_ptr->next = new;
}
