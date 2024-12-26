/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:14:57 by mmad              #+#    #+#             */
/*   Updated: 2023/11/20 19:17:34 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			last_occurrence = (char *)s;
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	else
		return ((char *)last_occurrence);
}
