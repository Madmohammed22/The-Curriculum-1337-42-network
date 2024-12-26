/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation_bunus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:38:21 by mmad              #+#    #+#             */
/*   Updated: 2024/07/04 13:47:44 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_is_eating(t_philo_non_shared *holder)
{
	size_t	start;

	start = holder->asset->x0;
	sem_wait(holder->asset->forks);
	ft_print_lock(holder, get_current_time() - start, holder->philosophers_id,
		"has taken a fork");
	sem_wait(holder->asset->forks);
	ft_print_lock(holder, get_current_time() - start, holder->philosophers_id,
		"has taken a fork");
	sem_wait(holder->asset->break_process2);
	holder->philosopher_last_eat = get_current_time();
	sem_post(holder->asset->break_process2);
	ft_print_lock(holder, get_current_time() - start, holder->philosophers_id,
		"is eating");
	ft_msleep(holder->asset->time_to_eat);
	sem_wait(holder->asset->break_process2);
	holder->eat_count++;
	sem_post(holder->asset->break_process2);
	sem_post(holder->asset->forks);
	sem_post(holder->asset->forks);
}

void	ft_is_sleeping(t_philo_non_shared *holder)
{
	size_t	start;

	start = holder->asset->x0;
	ft_print_lock(holder, get_current_time() - start, holder->philosophers_id,
		"is sleeping");
	ft_msleep(holder->asset->time_to_sleep);
}

void	ft_is_thinking(t_philo_non_shared *holder)
{
	size_t	start;

	start = holder->asset->x0;
	ft_print_lock(holder, get_current_time() - start, holder->philosophers_id,
		"is thinking");
}

void	philosopher_routine(t_philo_non_shared *holder)
{
	while (1)
	{
		sem_wait(holder->asset->break_process2);
		if (holder->asset->break_routine == 1)
		{
			sem_post(holder->asset->break_process2);
			return ;
		}
		sem_post(holder->asset->break_process2);
		if (holder->philosophers_id % 2 == 0)
			usleep(300);
		ft_is_eating(holder);
		ft_is_thinking(holder);
		usleep(1000);
		ft_is_sleeping(holder);
	}
}

void	ft_start_simulation(t_philo_non_shared *philo, pthread_t *Threads)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < philo->asset->number_of_philosophers)
	{
		pid = fork();
		if (pid == -1)
			return ;
		if (pid == 0)
		{
			philo->save = pid;
			pthread_create(&Threads[i], NULL, (void *)ft_monitor, &philo[i]);
			philosopher_routine(&philo[i]);
			pthread_join(Threads[i], NULL);
			exit(0);
		}
		i++;
	}
	i = 0;
	while (i < philo->asset->number_of_philosophers)
	{
		wait(NULL);
		i++;
	}
}
