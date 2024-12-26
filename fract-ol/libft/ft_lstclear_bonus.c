/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:03:21 by mmad              #+#    #+#             */
/*   Updated: 2023/11/19 19:24:51 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*temp;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		next = temp->next;
		(del)(temp->content);
		free(temp);
		temp = next;
	}
	*lst = NULL;
}
