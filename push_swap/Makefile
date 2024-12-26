# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 10:05:03 by mmad              #+#    #+#              #
#    Updated: 2024/12/26 01:03:51 by mmad             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC1 = push_swap.c

SRC2 = push_swap_stack_a_op.c push_swap_stack_b_op.c push_swap_utils1.c push_swap_utils2.c\
push_swap_utils3.c push_swap_utils4.c  swap_2.c swap_3.c swap_4.c swap_5.c ft_split.c ft_argv.c ft_atoi.c \
ft_sort_stack.c ft_call.c ft_call_sort.c get_next_line.c get_next_line_utils.c
 
SRC3 = checker.c

SRC4 = push_swap_stack_a_op_bonus.c push_swap_stack_b_op_bonus.c \
push_swap_stack_a_op_cont_bonus.c push_swap_utils1.c push_swap_utils2.c\
push_swap_utils3.c push_swap_utils4.c ft_split.c ft_argv.c ft_atoi.c \
ft_call.c get_next_line.c get_next_line_utils.c checker_utils.c

OBJ = $(SRC1:.c=.o) $(SRC2:.c=.o)
LOBJ = $(SRC3:.c=.o) $(SRC4:.c=.o)

NAME = push_swap
LNAME = checker

CC = cc 

CFLAGS =  -Wall -Wextra -Werror  

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(LNAME) : $(LOBJ)
		$(CC) $(CFLAGS) -o $(LNAME) $(LOBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

bonus: $(LNAME)

clean :
		rm -f $(OBJ) $(LOBJ)

fclean : clean
		rm -f $(NAME) $(LNAME)

re : fclean  all bonus

.PHONY : all clean fclean re bonus
