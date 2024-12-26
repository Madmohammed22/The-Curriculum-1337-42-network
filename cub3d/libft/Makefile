SRC = ft_atoi.c ft_hunt_leak.c ft_strlen.c ft_strchr.c ft_strdup.c\
	ft_strtrim.c ft_strncmp.c ft_substr.c ft_isdigit.c ft_strjoin.c\
	ft_split.c ft_strrchr.c ft_strcmp.c ft_strnstr.c ft_putstr_fd.c
#	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c  ft_isprint.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlcat.c\
	ft_strlcpy.c ft_tolower.c ft_toupper.c ft_strdup.c ft_itoa.c\
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_memchr.c\
	ft_putendl_fd.c ft_putnbr_fd.c ft_calloc.c  

BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \
ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)
OBJBONUS = $(BONUS:.c=.o)
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}
	@ar rc ${NAME} $(OBJ) $(OBJBONUS)

${NAME}:${OBJ} $(OBJBONUS)
	@ar rc ${NAME} $^

%.o: %.c
	@gcc ${CFLAGS} -c $< -o $@

bonus: ${OBJBONUS}

clean:
	@rm -f ${OBJ} ${OBJBONUS}

fclean: clean
	@rm -f ${NAME}

re:     fclean all bonus

.PHONY: all clean fclean re bonus\

.SECONDARY: ${OBJ} ${OBJBONUS}

