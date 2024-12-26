/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:28:04 by mmad              #+#    #+#             */
/*   Updated: 2024/02/06 14:54:13 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static char	**ft_free_if(char **array, int word)
{
	while (word >= 0)
	{
		free(array[word]);
		word--;
	}
	free(array);
	return (NULL);
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
				return (ft_free_if(array, word));
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
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array[words] = 0;
	array = ft_split_words(array, s, c);
	return (array);
}
