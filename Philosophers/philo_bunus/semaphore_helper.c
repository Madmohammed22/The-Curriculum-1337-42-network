/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:52:38 by mmad              #+#    #+#             */
/*   Updated: 2024/07/04 13:48:36 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	ft_pase_parameters(char *parameters)
{
	int	i;

	i = 0;
	while (parameters[i])
	{
		if (ft_isdigit(parameters[i]) != 1)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_pase_parameters_container(int argc, char **argv)
{
	int	i;
	int	number_of_philosophers;

	number_of_philosophers = ft_atoi(argv[1]);
	if (number_of_philosophers == 0)
		return (false);
	i = 1;
	while (i < argc)
	{
		if (ft_pase_parameters(argv[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

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

void	ft_print_lock(t_philo_non_shared *p, size_t time, int id, char *str)
{
	sem_wait(p->asset->break_process2);
	if (p->asset->break_routine == 0)
	{
		printf("%zu %d %s\n", time, id, str);
		sem_post(p->asset->break_process2);
		return ;
	}
	sem_post(p->asset->break_process2);
}
