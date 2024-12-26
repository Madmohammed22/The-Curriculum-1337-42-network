/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammedmad <mohammedmad@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:01:54 by mmad              #+#    #+#             */
/*   Updated: 2024/09/07 14:25:34 by mohammedmad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sep(const char s, char c)
{
	if (s == c || s == '\0')
		return (1);
	return (0);
}

static int	total_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (check_sep(s[i], c) == 0 && check_sep(s[i + 1], c) == 1)
			words++;
		i++;
	}
	return (words);
}

static char	**ft_split_words(char **array, const char *s, char c)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (check_sep(s[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (check_sep(s[i + j], c) == 0)
				j++;
			array[word] = ft_substr(s, i, j);
			if (array[word] == NULL)
			{
				return (NULL);
			}
			i += j;
			word++;
		}
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**array;

	if (!s)
		return (NULL);
	words = total_words(s, c);
	array = (char **)ft_malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array[words] = 0;
	array = ft_split_words(array, s, c);
	return (array);
}
