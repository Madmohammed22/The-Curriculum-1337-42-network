SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp Brain.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

CppFLAGS = -Wall -Wextra -Werror

CppVERSION = -std=c++98

NAME = main

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CppFLAGS) $(CppVERSION) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CC) $(CppFLAGS) $(CppVERSION) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

.SECONDARY : $(OBJ)
