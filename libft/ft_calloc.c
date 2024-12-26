/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:05:22 by mmad              #+#    #+#             */
/*   Updated: 2023/11/24 09:50:59 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

	buffer = malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		ft_bzero(buffer, 1);
		return (buffer);
	}
	ft_bzero(buffer, nmemb * size);
	return (buffer);
}
