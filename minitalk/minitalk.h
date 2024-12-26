/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:03:17 by mmad              #+#    #+#             */
/*   Updated: 2024/01/19 14:03:18 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_address(void *add);
int		ft_call_f(char format, va_list args);
int		ft_lowerhex(unsigned long nb);
int		ft_upperhex(unsigned int nb);
int		ft_putchar(char c);
int		ft_putnbr(int n);
void	ft_putstr_fd(char *s, int fd);
int		ft_putstr(char *str);

int		ft_putunsigned(unsigned int n);
int		ft_printf(const char *format, ...);
int		ft_atoi(const char *nptr);
#endif