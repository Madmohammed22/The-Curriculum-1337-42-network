/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:17:40 by mmad              #+#    #+#             */
/*   Updated: 2023/11/20 14:09:25 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
			return (temp_s1 - temp_s2);
		}
		if (temp_s1 == '\0' && temp_s2 == '\0')
			return (0);
	}
	return (0);
}
