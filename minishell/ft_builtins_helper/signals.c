/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abquaoub <abquaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:41:17 by abquaoub          #+#    #+#             */
/*   Updated: 2024/05/27 15:08:36 by abquaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

void	handle_signal(int sig)
{
	if (sig == SIGINT && g_ptr.mode == 0)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_ptr.data->status = 130;
	}
	else
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		ft_exit_status(130);
	}
}

void	handle_signal_quit(int sig)
{
	if (sig == SIGQUIT && g_ptr.mode == 0)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_ptr.data->status = 0;
	}
	else
	{
		printf("Quit (core dumped)\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		ft_exit_status(131);
	}
}

void	ft_handle_signals(void)
{
	if (signal(SIGINT, handle_signal) == SIG_ERR)
		printf("Error catch signal\n");
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal_quit);
	signal(SIGTERM, SIG_IGN);
}
