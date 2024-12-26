/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_threads.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:41:48 by mmad              #+#    #+#             */
/*   Updated: 2024/06/30 17:43:49 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	ft_monitor_helper(void *args)
{
	t_philosophers_data	*data_philos;
	int					i;

	data_philos = (t_philosophers_data *)args;
	i = 0;
	if (data_philos->philo->philo_eat_count != -1)
	{
		while (i < data_philos->philo->number_of_philosophers)
		{
			if ((data_philos[i].eat_count
					< data_philos->philo->philo_eat_count))
				return (false);
			i++;
		}
	}
	else
		return (false);
	return (true);
}

void	*ft_monitor_container(t_philosophers_data *data_philos)
{
	size_t	start;

	start = data_philos->philo->x0;
	pthread_mutex_lock(&data_philos->philo->monitor);
	pthread_mutex_lock(data_philos->right_fork);
	ft_msleep(data_philos->philo->time_to_die);
	printf(RED "%zu %d is dead\n" RESET, get_current_time() - start,
		data_philos->philosophers_id);
	data_philos->philo->break_routine = 1;
	pthread_mutex_unlock(data_philos->right_fork);
	pthread_mutex_unlock(&data_philos->philo->monitor);
	return (NULL);
}

void	*ft_main_monitor(t_philosophers_data *data_philos, int i)
{
	while (i < data_philos->philo->number_of_philosophers)
	{
		pthread_mutex_lock(&data_philos->philo->monitor);
		if ((get_current_time()
				- data_philos[i].philosopher_last_eat
				> (unsigned long)data_philos[i].philo->time_to_die)
			&& data_philos[i].philosopher_last_eat != 0)
		{
			printf(RED "%zu %d is dead\n" RESET, get_current_time()
				- data_philos[i].philo->x0, data_philos[i].philosophers_id);
			data_philos[i].philo->break_routine = 1;
			pthread_mutex_unlock(&data_philos->philo->monitor);
			return (NULL);
		}
		if (ft_monitor_helper(data_philos) == true)
		{
			data_philos[i].philo->break_routine = 1;
			pthread_mutex_unlock(&data_philos->philo->monitor);
			return (NULL);
		}
		pthread_mutex_unlock(&data_philos->philo->monitor);
		i++;
	}
	return (NULL);
}

void	*ft_monitor(void *args)
{
	int					i;
	t_philosophers_data	*data_philos;

	data_philos = (t_philosophers_data *)args;
	if (data_philos->philo->number_of_philosophers == 1)
		ft_monitor_container(data_philos);
	i = 0;
	while (data_philos->philo->break_routine == 0)
	{
		ft_main_monitor(&data_philos[i], i);
		i = 0;
	}
	return (NULL);
}
