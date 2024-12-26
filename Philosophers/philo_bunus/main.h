/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:21:08 by mmad              #+#    #+#             */
/*   Updated: 2024/07/04 15:58:36 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "main.h"
# include <assert.h>
# include <errno.h>
# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# define RED "\x1B[31m"
# define RESET "\x1B[0m"

typedef struct s_philo_shared
{
	int				number_of_philosophers;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			time_to_eat;
	int				break_routine;
	size_t			x0;
	int				philo_count;
	sem_t			*forks;
	sem_t			*break_process1;
	sem_t			*break_process2;
}					t_philo_shared;

typedef struct s_philo_non_shared
{
	int				philosophers_id;
	int				eat_count;
	size_t			philosopher_last_eat;
	pthread_t		threads;
	t_philo_shared	*asset;
	pid_t			save; //
}					t_philo_non_shared;

bool				ft_pase_parameters(char *parameters);
bool				ft_pase_parameters_container(int argc, char **argv);
size_t				get_current_time(void);
int					ft_msleep(size_t milliseconds);
void				ft_print_lock(t_philo_non_shared *p, size_t time, int id,
						char *str);
void				*ft_monitor_container(t_philo_non_shared *data_philos);
bool				ft_monitor_helper(void *args);
void				ft_kill_processes(t_philo_non_shared *data_philos);
void				*ft_main_monitor(t_philo_non_shared *data_philos);
void				*ft_monitor(void *args);
void				ft_is_eating(t_philo_non_shared *holder);
void				ft_is_sleeping(t_philo_non_shared *holder);
void				ft_is_thinking(t_philo_non_shared *holder);
void				philosopher_routine(t_philo_non_shared *holder);
void				ft_start_simulation(t_philo_non_shared *philo,
						pthread_t *Threads);
int					ft_atoi(const char *nptr);
int					ft_isdigit(int c);

#endif