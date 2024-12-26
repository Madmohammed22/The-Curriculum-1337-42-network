/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:18:01 by mmad              #+#    #+#             */
/*   Updated: 2023/12/01 20:19:11 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putunsigned(unsigned int n);
int	ft_lowerhex(unsigned long nb);
int	ft_upperhex(unsigned int nb);
int	ft_address(void *add);
int	ft_printf(const char *format, ...);
int	ft_call_f(char format, va_list args);

#endif