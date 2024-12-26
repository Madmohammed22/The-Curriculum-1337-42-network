/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abquaoub <abquaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 04:33:37 by abquaoub          #+#    #+#             */
/*   Updated: 2024/05/27 14:48:33 by abquaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_global	g_ptr;

void	ft_exec_pro(char *line)
{
	t_list	*head;

	head = NULL;
	ft_syntax(line);
	if (g_ptr.data->red == 1)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
		g_ptr.data->red = 0;
		g_ptr.data->status = 2;
	}
	else
	{
		g_ptr.mode = 1;
		head = ft_nested_pip(line);
		ft_nested_pip_ex(head, 1, 0);
	}
	g_ptr.flag = 0;
	ft_unlink(3);
	ft_unlink(0);
	g_ptr.save_file = NULL;
	g_ptr.save_desc = NULL;
}

void	change_env(void)
{
	t_list	*pp1;
	t_list	*pp2;
	t_list	*split;

	if (g_ptr.line)
	{
		split = split_end_or(g_ptr.line, " ", 0, 4);
		if (!split)
			return ;
		pp1 = ft_lstnew(ft_strjoin("_=", split->content));
		ft_separate_node(pp1);
		ft_separate_node(g_ptr.data->env_list);
		ft_if_exist_var_v2(g_ptr.data->env_list, pp1);
	}
	if (g_ptr.shell > 999)
		g_ptr.shell = 1;
	pp2 = ft_lstnew(ft_strjoin("SHLVL=", ft_itoa(g_ptr.shell)));
	ft_separate_node(pp2);
	ft_separate_node(g_ptr.data->env_list);
	ft_if_exist_var_v2(g_ptr.data->env_list, pp2);
}

int	main(int ac, char **av, char **env)
{
	char	*line;

	(void)av;
	ft_entry_values();
	initialize(NULL, g_ptr.data);
	ft_buffer_to_list(&g_ptr.data->env_list, env);
	if (ac != 1)
		return (1);
	while (1)
	{
		g_ptr.mode = 0;
		ft_handle_signals();
		line = ft_pwd();
		line = readline(line);
		ft_lstadd_back(&(g_ptr.head_free), ft_lstnew_v1(line));
		add_history(line);
		if (!line)
			break ;
		change_env();
		ft_exec_pro(line);
	}
	ft_free();
	return (0);
}

void	ft_free(void)
{
	t_list	*tmp;
	t_list	*head;

	head = g_ptr.head_free;
	tmp = NULL;
	while (head)
	{
		tmp = head->next;
		free(head->addr);
		ft_lstdelone(head, free);
		head = tmp;
	}
	free(g_ptr.data);
	printf("exit\n");
}
