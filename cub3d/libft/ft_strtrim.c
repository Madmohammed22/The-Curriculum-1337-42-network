/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammedmad <mohammedmad@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:56:54 by mmad              #+#    #+#             */
/*   Updated: 2024/09/04 22:43:30 by mohammedmad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c && *set != '\0')
			return (1);
		set++;
	}
	return (0);
}

static int	get_first_position(const char *s, const char *set)
{
	int	i;

	i = 0;
	while (s[i] && is_in_set(s[i], set))
		i++;
	return (i);
}

static int	get_last_position(const char *s, const char *set)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0 && is_in_set(s[i - 1], set))
		i--;
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trim;
	int		len;
	int		start;
	int		end;
	int		i;

	if (s1 == NULL)
		return (NULL);
	start = get_first_position(s1, set);
	end = get_last_position(s1, set);
	if (start > end)
	{
		trim = (char *)ft_malloc(1);
		trim[0] = '\0';
		return (trim);
	}
	len = end - start;
	trim = (char *)ft_malloc(len + 1);
	if (!trim)
		return (NULL);
	i = 0;
	while (i < len)
		trim[i++] = s1[start++];
	trim[i] = '\0';
	return (trim);
}
