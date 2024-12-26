/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:44:44 by mmad              #+#    #+#             */
/*   Updated: 2024/02/15 17:28:01 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buffer_1;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	buffer_1 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
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
	free(s1);
	return (buffer_1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	temp_s1;
	unsigned char	temp_s2;

	if (s1 == NULL && s2 == NULL)
		return (0);
	if (n == 0)
		return (0);
	while (n--)
	{
		temp_s1 = *s1++;
		temp_s2 = *s2++;
		if (temp_s1 != temp_s2)
		{
			return (1);
		}
		if (temp_s1 == '\0' && temp_s2 == '\0')
			return (0);
	}
	return (0);
}

int	get_len(char **s)
{
	int	j;

	j = 0;
	while (s[j])
		j++;
	return (j);
}
