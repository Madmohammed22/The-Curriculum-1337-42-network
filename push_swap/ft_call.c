/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:45:04 by mmad              #+#    #+#             */
/*   Updated: 2024/02/11 17:37:26 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (fd < 0 || !s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
	write(fd, "\n", 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*temp_s;
	char	*temp_dest;
	int		s_length;
	size_t	i;

	temp_s = (char *)s;
	s_length = ft_strlen(temp_s);
	temp_dest = malloc(sizeof(char) * s_length + 1);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substring = malloc(sizeof(char) * len + 1);
	if (!substring)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

int	ft__atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*nptr && *nptr == ' ') || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	sign = 1;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}
