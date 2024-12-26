/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:15:13 by mmad              #+#    #+#             */
/*   Updated: 2023/11/24 09:52:37 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destsize;
	size_t	i;

	i = 0;
	if (!dest && size == 0)
		return (ft_strlen(src));
	destsize = 0;
	while (destsize < size && dest[destsize])
		destsize++;
	if (destsize >= size)
		return (ft_strlen(src) + size);
	while (src[i] != '\0')
	{
		if (destsize + i < size - 1)
		{
			dest[destsize + i] = src[i];
			i++;
		}
		else
			break ;
	}
	dest[destsize + i] = '\0';
	return (destsize + ft_strlen(src));
}
