/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abquaoub <abquaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:45:18 by abquaoub          #+#    #+#             */
/*   Updated: 2024/05/27 13:59:46 by abquaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

char	*ft_generate(void)
{
	int		fd;
	char	*buff;
	int		i;
	char	*join;

	fd = open("/dev/random", O_RDWR);
	ft_lstadd_back(&g_ptr.save_desc, ft_lstnew_v2(fd));
	buff = malloc(11);
	ft_lstadd_back(&(g_ptr.head_free), ft_lstnew_v1(buff));
	read(fd, buff, 10);
	buff[10] = 0;
	i = 0;
	while (buff[i])
	{
		if (ft_isalnum(buff[i]) == 0)
			buff[i] = 'a';
		i++;
	}
	join = ft_strjoin("/tmp/.", buff);
	return (join);
}

char	*ft_remove_heredoc(char *str, t_list **head)
{
	t_str	strr;

	ini_str(&strr);
	strr.str = str;
	while (str[strr.i])
	{
		if (str[strr.i] == '$')
			ft_handel_expend(head, &strr, 1);
		else
		{
			strr.join = ft_new_strjoin(strr.join, str[strr.i]);
			strr.i++;
		}
	}
	if (!strr.join)
		strr.join = ft_strdup("");
	return (strr.join);
}

void	ft_dd(int i)
{
	(void)i;
	g_ptr.flag = 1;
	printf("\n");
	close(0);
}

void	ft_write_file(int fd, char *end)
{
	char	*buff;
	int		fd0;

	fd0 = dup(0);
	signal(SIGINT, ft_dd);
	while (1 && !g_ptr.flag)
	{
		buff = readline("> ");
		if (!buff || !ft_strcmp(buff, end))
			break ;
		ft_lstadd_back(&(g_ptr.head_free), ft_lstnew_v1(buff));
		buff = ft_remove_heredoc(buff, NULL);
		write(fd, buff, strlen(buff));
		write(fd, "\n", 1);
	}
	dup2(fd0, 0);
	close(fd0);
}

int	ft_read_stdin(char *end)
{
	int		fd;
	char	*file;

	file = ft_generate();
	ft_lstadd_back(&g_ptr.save_file, ft_lstnew(file));
	fd = open(file, O_CREAT | O_RDWR, 0600);
	ft_write_file(fd, end);
	close(fd);
	fd = open(file, O_CREAT | O_RDWR, 0400);
	ft_lstadd_back(&g_ptr.save_desc, ft_lstnew_v2(fd));
	return (fd);
}
