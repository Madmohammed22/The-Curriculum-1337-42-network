# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 15:28:46 by mmad              #+#    #+#              #
#    Updated: 2023/12/01 20:16:55 by mmad             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_putstr.c ft_putchar.c ft_putnbr.c ft_putunsigned.c ft_hexa.c ft_address.c ft_call_f.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $<
	ar rc $(NAME) $@

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean  all

.PHONY : all clean fclean re 
