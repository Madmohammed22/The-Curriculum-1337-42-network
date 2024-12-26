/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:02:22 by mmad              #+#    #+#             */
/*   Updated: 2024/01/19 14:02:53 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bit(int pid, int bit)
{
	int	signal;

	if (bit == 1)
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	if (kill(pid, signal) == -1)
		exit(1);
}

void	ft_send_char(int pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		ft_send_bit(pid, (c >> i) & 1);
		usleep(500);
		i--;
	}
}

void	ft_send_string(int pid, const char *str)
{
	while (*str)
		ft_send_char(pid, *str++);
	ft_send_char(pid, '\n');
	ft_send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [PID] [string]\n", 2);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("Invalid PID: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	ft_send_string(pid, argv[2]);
	return (0);
}
