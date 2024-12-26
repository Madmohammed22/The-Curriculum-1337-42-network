/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammedmad <mohammedmad@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:44:43 by mmad              #+#    #+#             */
/*   Updated: 2024/09/04 20:44:10 by mohammedmad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*temp_s;
	char	*temp_dest;
	int		s_length;
	size_t	i;

	temp_s = (char *)s;
	s_length = ft_strlen(temp_s);
	temp_dest = ft_malloc(sizeof(char) * s_length + 1);
	if (!temp_dest)
		return (NULL);
	i = 0;
	while (temp_s[i])
	{
		temp_dest[i] = temp_s[i];
		i++;
	}
	temp_dest[i] = '\0';
	return (temp_dest);
}
