NAME = philo

SRC =  main.c ft_initialize.c ft_simulation.c ft_monitor_threads.c\
		ft_time_functions.c Import_from_libft.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=leak
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread

all : $(NAME)

$(OBJ) : %.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -lpthread -o $(NAME)

clean :
# @make -s clean -C
	@rm -rf $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

.SECONDARY : $(OBJ)
