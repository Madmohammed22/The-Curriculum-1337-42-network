# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 23:23:31 by mmad              #+#    #+#              #
#    Updated: 2024/03/21 20:58:13 by mmad             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_render_fractol.c ft_grep_values.c  ft_handle_events.c  ft_on_events.c  main.c ft_utils.c
SRC_BONUS = ft_render_fractol_bonus.c ft_grep_values.c ft_handle_events.c  ft_on_events_bonus.c  main_bonus.c ft_utils.c 
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
NAME = fractol
LNAME = fractol_bonus

LMLX = /nfs/homes/mmad/Desktop/fractol_cursus/fractol/minilibx-linux/libmlx_Linux.a
FT_PRINTF = ./ft_printf/libftprintf.a
LIBFT = ./libft/libft.a
MLXCFLAGS = -lX11 -lXext -lmlx
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(LMLX) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLXCFLAGS) $(LMLX) $(FT_PRINTF) $(LIBFT)
$(LNAME): $(LIBFT) $(OBJ_BONUS) $(LMLX) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(LNAME) $(OBJ_BONUS) $(MLXCFLAGS) $(LMLX) $(FT_PRINTF) $(LIBFT)

$(LIBFT):
		make -C ./libft
		@echo "Libft done"

$(FT_PRINTF):
		make -C ./ft_printf
		@echo "ft_printf done"

%.o: %.c
		$(CC) $(CFLAGS) -c $<
bonus: $(LNAME)

clean:
		make -C ./libft clean
		make -C ./ft_printf clean
		rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
		make -C ./libft fclean
		make -C ./ft_printf fclean
		rm -f $(NAME) $(LNAME)

re: clean all

.PHONY: all clean fclean re bonus

.SECONDARY: $(OBJ) $(OBJ_BONUS)