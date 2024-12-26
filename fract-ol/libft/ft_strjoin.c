/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:55:50 by mmad              #+#    #+#             */
/*   Updated: 2023/11/20 00:40:06 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*buffer_1;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	buffer_1 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!buffer_1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		buffer_1[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		buffer_1[i++] = s2[j++];
	buffer_1[i] = '\0';
	return (buffer_1);
}
