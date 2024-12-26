/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:21:08 by mmad              #+#    #+#             */
/*   Updated: 2024/06/30 17:55:48 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <assert.h>
# include <errno.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define RED "\x1B[31m"
# define RESET "\x1B[0m"

typedef struct s_pthread_philosophers
{
	int						number_of_philosophers;
	int						time_to_die;
	int						time_to_sleep;
	int						time_to_eat;
	int						philo_eat_count;
	size_t					x0;
	pthread_mutex_t			*forks;
	pthread_mutex_t			monitor;
	int						break_routine;
	int						flag;
}							t_pthread_philosophers;

typedef struct s_philosophers_data
{
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	int						philosophers_id;
	int						eat_count;
	size_t					philosopher_last_eat;
	t_pthread_philosophers	*philo;
}							t_philosophers_data;

int							ft_atoi(const char *nptr);
int							ft_isdigit(int c);
bool						ft_monitor_helper(void *args);
void						*ft_monitor_container(
								t_philosophers_data *data_philos);
void						*ft_main_monitor(t_philosophers_data *data_philos,
								int i);
void						*ft_monitor(void *args);
void						ft_initialize_shared_philos(
								t_pthread_philosophers *shared_philo,
								char **argv, int num_philosophers);
void						ft_initialize_philos(
								t_philosophers_data *data_philos,
								t_pthread_philosophers *shared_philo,
								char **argv, int num_philosophers);
void						ft_print_lock(t_philosophers_data *p, size_t time,
								int id, char *str);
void						ft_sleeping_routine(t_philosophers_data *p);
void						ft_thinking_routine(t_philosophers_data *p);
void						ft_eating_routine(t_philosophers_data *p,
								pthread_mutex_t *first_fork,
								pthread_mutex_t *second_fork);
void						*philosopher_routine(void *data);
size_t						get_current_time(void);
int							ft_msleep(size_t milliseconds);
#endif
