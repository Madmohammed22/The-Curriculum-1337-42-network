NAME = philo_bonus

SRC =  semaphore.c semaphore_helper.c ft_monitor_precess.c ft_simulation_bunus.c \
		Import_from_libft.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=leak
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread

all : $(NAME)

$(OBJ) : %.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -lpthread -lrt -o $(NAME)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

.SECONDARY : $(OBJ)