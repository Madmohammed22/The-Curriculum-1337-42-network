/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammedmad <mohammedmad@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:29:41 by mmad              #+#    #+#             */
/*   Updated: 2024/09/04 21:05:29 by mohammedmad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*temp_s;
	int		length;
	char	*space;
	int		i;

	if (!s || !f)
		return (NULL);
	temp_s = (char *)s;
	length = ft_strlen(s);
	space = (char *)ft_malloc(length + 1);
	if (space == NULL)
		return (NULL);
	i = 0;
	while (temp_s[i])
	{
		space[i] = f(i, temp_s[i]);
		i++;
	}
	space[i] = '\0';
	return (space);
}
