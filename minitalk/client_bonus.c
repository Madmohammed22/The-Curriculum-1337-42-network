/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:02:04 by mmad              #+#    #+#             */
/*   Updated: 2024/01/19 14:06:01 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	ft_handle_succ_sig(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message was sent successfully");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_handler = &ft_handle_succ_sig;
	sa.sa_flags = SA_RESTART;
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
	sigaction(SIGUSR1, &sa, NULL);
	ft_send_string(pid, argv[2]);
	return (0);
}
