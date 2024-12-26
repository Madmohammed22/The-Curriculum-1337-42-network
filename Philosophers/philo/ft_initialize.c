/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_shared_and_non_shared_philos.        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:51:24 by mmad              #+#    #+#             */
/*   Updated: 2024/06/30 17:53:03 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_initialize_shared_philos(t_pthread_philosophers *shared_philo,
				char **argv, int num_philosophers)
{
	int	i;

	shared_philo->number_of_philosophers = atoi(argv[1]);
	shared_philo->time_to_die = atoi(argv[2]);
	shared_philo->time_to_eat = atoi(argv[3]);
	shared_philo->time_to_sleep = atoi(argv[4]);
	shared_philo->x0 = get_current_time();
	if (argv[5])
		shared_philo->philo_eat_count = ft_atoi(argv[5]);
	else
		shared_philo->philo_eat_count = -1;
	shared_philo->forks = malloc(sizeof(pthread_mutex_t) * num_philosophers);
	shared_philo->break_routine = 0;
	shared_philo->flag = 0;
	pthread_mutex_init(&shared_philo->monitor, NULL);
	i = 0;
	while (i < num_philosophers)
		pthread_mutex_init(&shared_philo->forks[i++], NULL);
}

void	ft_initialize_philos(t_philosophers_data *data_philos,
		t_pthread_philosophers *shared_philo, char **argv, int num_philosophers)
{
	int	i;

	ft_initialize_shared_philos(shared_philo, argv, num_philosophers);
	i = 0;
	while (i < num_philosophers)
	{
		data_philos[i].philo = shared_philo;
		data_philos[i].philosophers_id = i + 1;
		data_philos[i].eat_count = 0;
		data_philos[i].philosopher_last_eat = 0;
		data_philos[i].left_fork = &shared_philo->forks[i];
		data_philos[i].right_fork = &shared_philo->forks[(i + 1)
			% num_philosophers];
		i++;
	}
}
