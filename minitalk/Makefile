# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 10:27:29 by mmad              #+#    #+#              #
#    Updated: 2024/01/19 14:17:30 by mmad             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SSRC = server.c ft_printf.c ft_atoi.c ft_putstr_fd.c ft_putstr.c ft_putchar.c \
ft_putnbr.c ft_putunsigned.c ft_hexa.c ft_address.c ft_call_f.c

CSRC = client.c ft_printf.c ft_atoi.c ft_putstr_fd.c ft_putstr.c ft_putchar.c \
ft_putnbr.c ft_putunsigned.c ft_hexa.c ft_address.c ft_call_f.c

BONUS_SSRC = server_bonus.c ft_printf.c ft_atoi.c ft_putstr_fd.c ft_putstr.c ft_putchar.c \
ft_putnbr.c ft_putunsigned.c ft_hexa.c ft_address.c ft_call_f.c

BONUS_CSRC = client_bonus.c ft_printf.c ft_atoi.c ft_putstr_fd.c ft_putstr.c ft_putchar.c \
ft_putnbr.c ft_putunsigned.c ft_hexa.c ft_address.c ft_call_f.c

OBJS = $(SSRC:.c=.o)
OBJC = $(CSRC:.c=.o)

OBJ_BONUSS = $(BONUS_SSRC:.c=.o)
OBJ_BONUSC = $(BONUS_CSRC:.c=.o)

SNAME = server
CNAME = client
BONUS_SNAME = server_bonus
BONUS_CNAME = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(SNAME) $(CNAME)

$(SNAME) : $(OBJS) 
	$(CC) $(CFLAGS) -o $(SNAME) $(OBJS)

$(CNAME) : $(OBJC)
	$(CC) $(CFLAGS) -o $(CNAME) $(OBJC)

$(BONUS_SNAME) : $(OBJ_BONUSS)
	$(CC) $(CFLAGS) -o $(BONUS_SNAME) $(OBJ_BONUSS)

$(BONUS_CNAME) : $(OBJ_BONUSC)
	$(CC) $(CFLAGS) -o $(BONUS_CNAME) $(OBJ_BONUSC)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

bonus: $(BONUS_SNAME) $(BONUS_CNAME)

clean :
	rm -f $(OBJS) $(OBJC) $(OBJ_BONUSS) $(OBJ_BONUSC)

fclean : clean
	rm -f $(SNAME) $(CNAME) $(BONUS_SNAME) $(BONUS_CNAME)

re : fclean all

.PHONY : all clean fclean re bonus
