/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_precess.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:35:24 by mmad              #+#    #+#             */
/*   Updated: 2024/07/04 18:34:06 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*ft_monitor_container(t_philo_non_shared *data_philos)
{
	size_t	start;

	start = data_philos->asset->x0;
	sem_wait(data_philos->asset->break_process1);
	ft_msleep(data_philos->asset->time_to_die);
	printf(RED "%zu %d is dead\n" RESET, get_current_time() - start,
		data_philos->philosophers_id);
	sem_post(data_philos->asset->break_process1);
	return (NULL);
}

bool	ft_monitor_helper(void *args)
{
	t_philo_non_shared	*data_philos;

	data_philos = (t_philo_non_shared *)args;
	if (data_philos->asset->philo_count != -1)
	{
		if ((data_philos->eat_count < data_philos->asset->philo_count))
			return (false);
	}
	else
		return (false);
	data_philos->asset->break_routine = 1;
	return (true);
}

void	ft_kill_processes(t_philo_non_shared *data_philos)
{
	bool	run;
	int		i;

	run = true;
	while (run)
	{
		i = 0;
		while (i < data_philos->asset->number_of_philosophers)
		{
			kill(data_philos->save, SIGINT);
			i++;
		}
		run = false;
	}
}

void	*ft_main_monitor(t_philo_non_shared *data_philos)
{
	sem_wait(data_philos->asset->break_process2);
	if ((get_current_time()
			- data_philos->philosopher_last_eat
			> (unsigned long)data_philos->asset->time_to_die)
		&& data_philos->philosopher_last_eat != 0)
	{
		printf(RED "%zu %d is dead\n" RESET, get_current_time()
			- data_philos->asset->x0, data_philos->philosophers_id);
		data_philos->asset->break_routine = 1;
		ft_kill_processes(data_philos);
		sem_post(data_philos->asset->break_process2);
		exit(1);
	}
	if (ft_monitor_helper(data_philos) == true)
	{
		data_philos->asset->break_routine = 1;
		sem_post(data_philos->asset->break_process2);
		exit(0);
	}
	sem_post(data_philos->asset->break_process2);
	return (NULL);
}

void	*ft_monitor(void *args)
{
	t_philo_non_shared	*data_philos;

	data_philos = (t_philo_non_shared *)args;
	while (data_philos->asset->break_routine == 0)
	{
		if (data_philos->asset->number_of_philosophers == 1)
		{
			ft_monitor_container(data_philos);
			exit(1);
		}
		ft_main_monitor(data_philos);
	}
	return (NULL);
}
