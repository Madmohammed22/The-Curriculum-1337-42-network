/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:15:28 by mmad              #+#    #+#             */
/*   Updated: 2024/09/11 12:16:31 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		return (NULL);
	}
	remainder = ft_malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!remainder)
		return (NULL);
	j = 0;
	i++;
	while (buffer[i])
		remainder[j++] = buffer[i++];
	remainder[j] = '\0';
	return (remainder);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)ft_malloc(sizeof(char) * (i + 2));
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

char	*read_from_fd(int fd, char *result)
{
	int		bytes_read;
	char	*buffer;

	buffer = ft_malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(result, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		result = ft_strjoin(result, buffer);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*content_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (0);
	content_buffer = read_from_fd(fd, content_buffer);
	if (!content_buffer)
		return (NULL);
	line = get_line(content_buffer);
	content_buffer = get_remainder(content_buffer);
	return (line);
}
