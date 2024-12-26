/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:57:49 by mmad              #+#    #+#             */
/*   Updated: 2024/06/30 17:43:49 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_msleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
