/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:43:23 by mmad              #+#    #+#             */
/*   Updated: 2024/02/15 22:54:15 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_remainder(char *buffer)
{
	int		i;
	int		j;
	char	*remainder;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	remainder = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!remainder)
		return (NULL);
	j = 0;
	i++;
	while (buffer[i])
		remainder[j++] = buffer[i++];
	remainder[j] = '\0';
	free(buffer);
	return (remainder);
}

static char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*read_from_fd(int fd, char *result)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(result, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			if (result)
				free(result);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		result = ft_strjoin(result, buffer);
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*content_buffer;
	char		*line;

	if (fd == INVALID_READ)
		return (free(content_buffer), NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (0);
	content_buffer = read_from_fd(fd, content_buffer);
	if (!content_buffer)
		return (NULL);
	line = get_line(content_buffer);
	content_buffer = get_remainder(content_buffer);
	return (line);
}
