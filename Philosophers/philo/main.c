/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:25:25 by mmad              #+#    #+#             */
/*   Updated: 2024/06/14 15:22:29 by mmad             ###   ########.fr       */
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

void	ft_clean_up(t_pthread_philosophers *shared_philo,
		t_philosophers_data *data_philos, pthread_t *threads, char **argv)
{
	int	i;
	int	number_of_philosophers;

	number_of_philosophers = ft_atoi(argv[1]);
	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_mutex_destroy(&shared_philo->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&shared_philo->monitor);
	free(shared_philo->forks);
	free(shared_philo);
	free(threads);
	free(data_philos);
}

int	main(int argc, char **argv)
{
	int						i;
	pthread_t				monitor_thread;
	t_philosophers_data		*data_philos;
	t_pthread_philosophers	*shared_philo;
	pthread_t				*threads;

	if ((argc <= 4))
		return (1);
	if (ft_pase_parameters_container(argc, argv) == false)
		return (1);
	data_philos = malloc(sizeof(t_philosophers_data) * ft_atoi(argv[1]));
	shared_philo = malloc(sizeof(t_pthread_philosophers) * ft_atoi(argv[1]));
	threads = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	if (!data_philos || !shared_philo || !threads)
		return (ft_clean_up(shared_philo, data_philos, threads, argv), 1);
	ft_initialize_philos(data_philos, shared_philo, argv, ft_atoi(argv[1]));
	i = -1;
	while (++i < ft_atoi(argv[1]))
		pthread_create(&threads[i], NULL, (void *)philosopher_routine,
			&data_philos[i]);
	pthread_create(&monitor_thread, NULL, ft_monitor, data_philos);
	pthread_join(monitor_thread, NULL);
	ft_clean_up(shared_philo, data_philos, threads, argv);
	return (0);
}
