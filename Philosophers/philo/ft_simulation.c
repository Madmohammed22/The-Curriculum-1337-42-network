/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:55:09 by mmad              #+#    #+#             */
/*   Updated: 2024/07/04 10:29:28 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_print_lock(t_philosophers_data *p, size_t time, int id, char *str)
{
	pthread_mutex_lock(&p->philo->monitor);
	if (p->philo->break_routine == 0)
	{
		printf("%zu %d %s\n", time, id, str);
		pthread_mutex_unlock(&p->philo->monitor);
		return ;
	}
	pthread_mutex_unlock(&p->philo->monitor);
}

void	ft_sleeping_routine(t_philosophers_data *p)
{
	size_t	start;

	start = p->philo->x0;
	ft_print_lock(p, get_current_time() - start, p->philosophers_id,
		"is sleeping");
	ft_msleep(p->philo->time_to_sleep);
}

void	ft_thinking_routine(t_philosophers_data *p)
{
	size_t	start;

	start = p->philo->x0;
	ft_print_lock(p, get_current_time() - start, p->philosophers_id,
		"is thinking");
}

void	ft_eating_routine(t_philosophers_data *p, pthread_mutex_t *first_fork,
		pthread_mutex_t *second_fork)
{
	size_t	start;

	start = p->philo->x0;
	first_fork = p->left_fork;
	second_fork = p->right_fork;
	if (p->philosophers_id % 2 != 0)
	{
		first_fork = p->right_fork;
		second_fork = p->left_fork;
	}
	pthread_mutex_lock(first_fork);
	ft_print_lock(p, get_current_time() - start, p->philosophers_id,
		"has taken a fork");
	pthread_mutex_lock(second_fork);
	ft_print_lock(p, get_current_time() - start, p->philosophers_id,
		"has taken a fork");
	pthread_mutex_lock(&p->philo->monitor);
	p->philosopher_last_eat = get_current_time();
	p->eat_count++;
	pthread_mutex_unlock(&p->philo->monitor);
	ft_print_lock(p, get_current_time() - start, p->philosophers_id,
		"is eating");
	ft_msleep(p->philo->time_to_eat);
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
}

void	*philosopher_routine(void *data)
{
	t_philosophers_data	*p;
	pthread_mutex_t		*first_fork;
	pthread_mutex_t		*second_fork;

	first_fork = NULL;
	second_fork = NULL;
	p = (t_philosophers_data *)data;
	if (p->philo->number_of_philosophers == 1)
		return (NULL);
	while (1)
	{
		pthread_mutex_lock(&p->philo->monitor);
		if (p->philo->break_routine == 1)
		{
			pthread_mutex_unlock(&p->philo->monitor);
			return (NULL);
		}
		pthread_mutex_unlock(&p->philo->monitor);
		ft_eating_routine(p, first_fork, second_fork);
		ft_sleeping_routine(p);
		ft_thinking_routine(p);
		usleep(1000);
	}
	return (NULL);
}
