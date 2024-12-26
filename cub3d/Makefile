#______colors______#
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
PURPLE = \033[0;35m
PINK = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

#______command and their flags______#
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address#-Ofast
MLXFLAGS = -lmlx -lXext -lX11 -lm 

#______directories______#
OBJ_DIR = obj
SRC_LGC_DIR = src/logic
SRC_PARS_DIR = src/parsing
INCLUDES = inc
LIB_INCLUDES = libft
#______directories <bonus______#
OBJ_DIR_BNS = obj_bonus
SRC_LGC_DIR_BNS = src_bonus/logic
SRC_PARS_DIR_BNS = src_bonus/parsing
INCLUDES_BNS = inc_bonus

#______mandatory and bonus files______#
FILES_EXEC := exit.c inputs.c rendering.c draw.c init.c\
		convert.c raycasting.c horizontal_cast.c vertical_cast.c\
		draw_utils.c image_updating.c rendering3d.c init_textures.c
FILES_PARS := main.c bfs.c helper_functions.c pars_map_holdercd.c enqueue.c\
		pars_map_holdercd_cont.c ft_pars_for_each.c pars_c_Floor.c\
		pars_texturs.c get_next_line.c pars_c_floor_utils.c scan_map_holder.c \
		helper_functions2.c pars_c_floor_utils2.c enqueue_helper.c
#______bonus files______#
FILES_EXEC_BNS := $(FILES_EXEC) firstPerson.c firstPerson_init.c firstPerson_initPath.c\
			firstPerson_utils.c inputs_mouse.c image_updating_utils.c
FILES_PARS_BNS := $(FILES_PARS) func_bonus.c

#______patterns and substitutions______#
SOURCES := $(addprefix $(SRC_LGC_DIR)/, $(FILES_EXEC)) $(addprefix $(SRC_PARS_DIR)/, $(FILES_PARS))
OBJECTS := $(patsubst $(SRC_LGC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
OBJECTS := $(patsubst $(SRC_PARS_DIR)/%.c, $(OBJ_DIR)/%.o, $(OBJECTS))
HEADERS := $(INCLUDES)/cub3d.h $(LIB_INCLUDES)/libft.h $(INCLUDES)/structs.h $(INCLUDES)/macros.h

#______patterns and substitutions <bonus>______#
SOURCES_BNS := $(addprefix $(SRC_LGC_DIR_BNS)/, $(FILES_EXEC_BNS)) $(addprefix $(SRC_PARS_DIR_BNS)/, $(FILES_PARS_BNS))
OBJECTS_BNS := $(patsubst $(SRC_LGC_DIR_BNS)/%.c, $(OBJ_DIR_BNS)/%.o, $(SOURCES_BNS))
OBJECTS_BNS := $(patsubst $(SRC_PARS_DIR_BNS)/%.c, $(OBJ_DIR_BNS)/%.o, $(OBJECTS_BNS))
HEADERS_BNS := $(INCLUDES_BNS)/cub3d.h $(LIB_INCLUDES)/libft.h $(INCLUDES_BNS)/structs.h $(INCLUDES_BNS)/macros.h $(INCLUDES_BNS)/enums.h

#______static library name______#
NAME = cub3D
BONUS_NAME = cub3D_bonus
LIB = libft

#______________Rules______________#
#______mandatory______#
all: $(NAME)

$(NAME): $(OBJECTS) $(LIB)/libft.a
	@$(CC) $(CFLAGS) $^ -I$(INCLUDES) -I$(LIB_INCLUDES) $(MLXFLAGS) -o $@
	@echo "$(GREEN)$(NAME) Compiled !$(RESET)"

# impicit rule for logic mandatory
$(OBJ_DIR)/%.o: $(SRC_LGC_DIR)/%.c $(HEADERS)
	@echo "$(CYAN)Compiling {$(MAGENTA)$< to $@$(CYAN)}$(RESET)"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIB_INCLUDES) -c $< -o $@
# impicit rule for parsing mandatory
$(OBJ_DIR)/%.o: $(SRC_PARS_DIR)/%.c $(HEADERS)
	@echo "$(CYAN)Compiling {$(MAGENTA)$< to $@$(CYAN)}$(RESET)"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIB_INCLUDES) -c $< -o $@
#______bonus______#
$(BONUS_NAME): $(OBJECTS_BNS) $(LIB)/libft.a
	@$(CC) $(CFLAGS) $^ -I$(INCLUDES_BNS) -I$(LIB_INCLUDES) $(MLXFLAGS) -o $@
	@echo "$(GREEN)$(BONUS_NAME) Compiled !$(RESET)"

# impicit rule for logic bonus
$(OBJ_DIR_BNS)/%.o: $(SRC_LGC_DIR_BNS)/%.c $(HEADERS_BNS)
	@echo "$(CYAN)Compiling {$(MAGENTA)$< to $@$(CYAN)}$(RESET)"
	@mkdir -p $(OBJ_DIR_BNS)
	@$(CC) $(CFLAGS) -I$(INCLUDES_BNS) -I$(LIB_INCLUDES) -c $< -o $@
# impicit rule for parsing bonus
$(OBJ_DIR_BNS)/%.o: $(SRC_PARS_DIR_BNS)/%.c $(HEADERS_BNS)
	@echo "$(CYAN)Compiling {$(MAGENTA)$< to $@$(CYAN)}$(RESET)"
	@mkdir -p $(OBJ_DIR_BNS)
	@$(CC) $(CFLAGS) -I$(INCLUDES_BNS) -I$(LIB_INCLUDES) -c $< -o $@

$(LIB)/%.a:
	@echo "$(YELLOW)Compiling libft$(RESET)"
	@$(MAKE) all -C $(LIB)

re: fclean all

rebonus: fclean
	@echo "$(YELLOW)Recompiling bonus$(RESET)"
	@$(MAKE) bonus

run: $(NAME)
	./$< maps/mandatory/library.cub
runbonus: $(BONUS_NAME)
	./$< maps/bonus/library.cub

bonus: $(BONUS_NAME)
#______cleaning______#
clean:
	@echo "$(RED)Cleaning$(RESET)"
	@$(RM) $(OBJ_DIR)
	@$(RM) $(OBJ_DIR_BNS)
	@$(MAKE) -C $(LIB) clean
	@echo "$(RED)Cleaned$(RESET)"
fclean: clean
	@echo "$(RED)fcleaning$(RESET)"
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@$(MAKE) -C $(LIB) fclean
	@echo "$(RED)fcleaned$(RESET)"

.SECONDARY: $(OBJECTS) $(OBJECTS_BNS)