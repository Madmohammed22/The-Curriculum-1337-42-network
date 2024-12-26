SRC = main.cpp Base.cpp A.cpp B.cpp C.cpp
# B.cpp C.cpp
OBJ = $(SRC:.cpp=.o)

CC = c++
# -Wall -Wextra -Werror 
# CppFLAGS =  -g3 -fsanitize=address -static-libasan -fno-omit-frame-pointer
CppFLAGS =  -g3 

CppVERSION = -std=c++98 ##-std=c++11 #  

NAME = convert

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
