/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:32:18 by mmad              #+#    #+#             */
/*   Updated: 2024/02/15 23:03:29 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef INVALID_READ 
#  define INVALID_READ -1
# endif

char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		get_len(char **s);
#endif
