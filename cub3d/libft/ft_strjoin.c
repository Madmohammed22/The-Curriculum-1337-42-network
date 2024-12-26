/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammedmad <mohammedmad@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:55:50 by mmad              #+#    #+#             */
/*   Updated: 2024/09/07 14:26:02 by mohammedmad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buffer_1;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)ft_malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	buffer_1 = (char *)ft_malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof(char));
	if (!buffer_1)
		return (NULL);
	i = -1;
	while (s1[++i])
		buffer_1[i] = s1[i];
	j = 0;
	while (s2[j])
		buffer_1[i++] = s2[j++];
	buffer_1[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (buffer_1);
}
