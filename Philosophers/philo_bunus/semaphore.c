/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:34:19 by mmad              #+#    #+#             */
/*   Updated: 2024/07/04 15:56:43 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	initialize_philosophers_asset(t_philo_shared *asset,
		int num_philosophers, char **argv)
{
	asset->number_of_philosophers = num_philosophers;
	asset->x0 = get_current_time();
	asset->time_to_die = atoi(argv[2]);
	asset->time_to_eat = atoi(argv[3]);
	asset->time_to_sleep = atoi(argv[4]);
	if (argv[5])
		asset->philo_count = ft_atoi(argv[5]);
	else
		asset->philo_count = -1;
	asset->break_routine = 0;
}

void	initialize_philosophers(t_philo_non_shared *data_philo,
								t_philo_shared *asset,
								int num_philosophers,
								char **argv)
{
	int	i;

	initialize_philosophers_asset(asset, num_philosophers, argv);
	sem_unlink("forks");
	sem_unlink("break_process1");
	sem_unlink("break_process2");
	asset->forks = sem_open("forks", O_CREAT, 0644, num_philosophers);
	asset->break_process1 = sem_open("break_process1", O_CREAT, 0644, 1);
	asset->break_process2 = sem_open("break_process2", O_CREAT, 0644, 1);
	i = -1;
	while (++i < num_philosophers)
	{
		data_philo[i].asset = asset;
		data_philo[i].philosophers_id = i + 1;
		data_philo[i].eat_count = 0;
		data_philo[i].philosopher_last_eat = 0;
	}
}

void	ft_clean_up(t_philo_shared *shared_assets, t_philo_non_shared *philo)
{
	sem_close(philo->asset->forks);
	sem_close(philo->asset->break_process1);
	sem_close(philo->asset->break_process2);
	sem_unlink("forks");
	sem_unlink("break_process1");
	sem_unlink("break_process2");
	free(philo);
	free(shared_assets);
}

int	main(int argc, char **argv)
{
	int					number_of_philosophers;
	t_philo_shared		*shared_assets;
	t_philo_non_shared	*data_philo;

	if (argc <= 4)
		return (1);
	if (ft_pase_parameters_container(argc, argv) == false)
		return (1);
	number_of_philosophers = atoi(argv[1]);
	shared_assets = malloc(sizeof(t_philo_shared) * number_of_philosophers);
	data_philo = malloc(sizeof(t_philo_non_shared) * number_of_philosophers);
	initialize_philosophers(data_philo, shared_assets, number_of_philosophers,
		argv);
	ft_start_simulation(data_philo, &data_philo->threads);
	ft_clean_up(shared_assets, data_philo);
	return (0);
}
