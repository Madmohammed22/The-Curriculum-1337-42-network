/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:01:41 by mmad              #+#    #+#             */
/*   Updated: 2024/01/19 14:14:26 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handle_signal(int signum)
{
	static unsigned char	ch = 0;
	static int				count_bit = 0;

	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		ch = ch << 1;
		if (signum == SIGUSR1)
			ch = ch | 1;
		count_bit++;
	}
	if (count_bit == 8)
	{
		write(1, &ch, 1);
		count_bit = 0;
		ch = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	printf("Server PID: %d\n", getpid());
	sa.sa_handler = &ft_handle_signal;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
