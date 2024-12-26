/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:50:47 by mmad              #+#    #+#             */
/*   Updated: 2023/11/22 20:20:15 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if ((!big || !little) && len == 0)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && i + j < len)
		{
			if (big[i + j] == little[j])
			{
				j++;
			}
			else
				break ;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
