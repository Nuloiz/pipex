NAME := pipex

CC := gcc

CFLAGS := -Wall -Wextra -Werror -g
# CFLAGS := $(CFLAGS) -fsanitize=address
SRC := main.c input_check.c pipex.c cmds.c paths.c free.c

SRC_DIR := src
OBJ_DIR := obj

INCLUDES := -I includes -I tools/libft

OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C tools/libft
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) tools/libft/libft.a
	@echo "Linking $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c includes/
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	@echo "Compiling $<"

clean:
	@rm -rf $(OBJ_DIR)
	@make -C tools/libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C tools/libft fclean

re: fclean all

.PHONY: all clean fclean re
