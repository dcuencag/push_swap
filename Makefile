NAME = push_swap

SRC = src/main.c src/is_valid.c src/utils.c src/stack.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
INCLUDES = -Iincludes -Ilibft

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a
LDFLAGS = -L$(LIBFT_DIR) -lft

RANDOM_DIR = ./random_gen
RANDOM_BIN = $(RANDOM_DIR)/random_gen

N ?= 23

all:
	@echo "\033[1;35m==================================\033[0m"
	@echo "\033[1;31m→ Checking build for push_swap...\033[0m"
	@echo "\033[1;35m==================================\033[0m"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@if [ ! -f $(NAME) ]; then \
		echo "\033[1;35m========================\033[0m"; \
		echo "\033[1;34m→ Building push_swap...\033[0m"; \
		echo "\033[1;35m========================\033[0m"; \
	fi
	@$(MAKE) -s $(NAME)
	@echo "\033[1;35m=========================================\033[0m"
	@echo "\033[1;32m✓ Push_swap build completed successfully\033[0m"
	@echo "\033[1;35m=========================================\033[0m"

$(NAME): $(OBJ)
	@echo "\033[1;35m==================================\033[0m"
	@echo "\033[1;32m→ Linking executable push_swap...\033[0m"
	@echo "\033[1;35m==================================\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LDFLAGS) -o $(NAME)

src/%.o: src/%.c
	@echo "\033[1;34m→ Compiling $<\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean: clean_random
	@$(MAKE) -s clean -C $(LIBFT_DIR)
	@rm -f $(OBJ)
	@echo "\033[1;35m==================\033[0m"
	@echo "\033[1;33m✓ Clean completed\033[0m"
	@echo "\033[1;35m==================\033[0m"

fclean: clean fclean_random
	@$(MAKE) -s fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "\033[1;35m=======================\033[0m"
	@echo "\033[1;33m✓ Full clean completed\033[0m"
	@echo "\033[1;35m=======================\033[0m"

re: fclean all

random:
	@$(MAKE) -s -C $(RANDOM_DIR)

run-random: random
	@echo "\033[1;35m==================================\033[0m"
	@echo "\033[1;36m→ Running random_gen with $(N) numbers...\033[0m"
	@echo "\033[1;35m==================================\033[0m"
	@$(RANDOM_BIN) $(N)

clean_random:
	@$(MAKE) -s clean -C $(RANDOM_DIR)

fclean_random:
	@$(MAKE) -s fclean -C $(RANDOM_DIR)

.PHONY: all clean fclean re random run-random clean_random fclean_random
