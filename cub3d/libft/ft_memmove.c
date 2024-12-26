/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:42:10 by mmad              #+#    #+#             */
/*   Updated: 2023/11/24 13:02:28 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*temp_dest;
	const char	*temp_src;
	size_t		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	temp_dest = (char *)dest;
	temp_src = (const char *)src;
	i = 0;
	if (dest == src || n == 0)
		return (dest);
	if (dest > src)
	{
		while (n--)
			((char *)dest)[n] = ((const char *)src)[n];
	}
	else
	{
		while (i < n)
		{
			temp_dest[i] = temp_src[i];
			i++;
		}
	}
	return (dest);
}
