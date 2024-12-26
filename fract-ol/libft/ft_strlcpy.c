/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:06:03 by mmad              #+#    #+#             */
/*   Updated: 2023/11/20 15:10:03 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*temp_dest;
	const char	*temp_src;
	size_t		src_length;
	size_t		i;

	temp_dest = dst;
	temp_src = src;
	src_length = ft_strlen(src);
	if (size == 0)
		return (src_length);
	i = 0;
	while (temp_src[i] && i < size - 1)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	temp_dest[i] = '\0';
	return (src_length);
}
