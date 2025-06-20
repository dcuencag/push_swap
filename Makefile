NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude -Ilibft

SRC = \
	src/main.c \
	src/init/parser.c \
	src/init/init_stack.c \
	src/utils/utils.c \
	src/utils/validate.c \
	src/stack/stack_ops.c \
	src/stack/rotate_ops.c \
	src/algorithm/radix_sort.c \
	src/algorithm/sort_small.c \
	src/debug/print_stack.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a
LDFLAGS = -L$(LIBFT_DIR) -lft

RANDOM_DIR = random_gen
RANDOM_BIN = random_gen/random_gen

all:
	@echo "\033[1;35m===============================\033[0m"
	@echo "\033[1;31m→ Checking build for push_swap...\033[0m"
	@echo "\033[1;35m===============================\033[0m"
	@if [ ! -f $(NAME) ]; then \
		echo "\033[1;35m=======================\033[0m"; \
		echo "\033[1;34m→ Building push_swap...\033[0m"; \
		echo "\033[1;35m=======================\033[0m"; \
	fi
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) $(NAME)
	@echo "\033[1;35m==========================================\033[0m"
	@echo "\033[1;32m✓ Push_swap build completed successfully\033[0m"
	@echo "\033[1;35m==========================================\033[0m"

$(NAME): $(OBJ)
	@echo "\033[1;35m=========================\033[0m"
	@echo "\033[1;34m→ Linking push_swap...\033[0m"
	@echo "\033[1;35m=========================\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c
	@echo "\033[1;36m→ Compiling $<\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(RANDOM_DIR) clean
	@echo "\033[1;35m==================\033[0m"
	@echo "\033[1;33m✓ Clean completed\033[0m"
	@echo "\033[1;35m==================\033[0m"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(RANDOM_DIR) fclean
	@echo "\033[1;35m=======================\033[0m"
	@echo "\033[1;33m✓ Full clean completed\033[0m"
	@echo "\033[1;35m=======================\033[0m"

re: fclean all

random:
	@$(MAKE) -s -C $(RANDOM_DIR)

N = 23
run-random: random
	@echo "\033[1;35m==================================\033[0m"
	@echo "\033[1;36m→ Running random_gen with $(N) numbers...\033[0m"
	@echo "\033[1;35m==================================\033[0m"
	@$(RANDOM_BIN) $(N)

clean_random:
	@$(MAKE) -s clean -C $(RANDOM_DIR)

fclean_random:
	@$(MAKE) -s fclean -C $(RANDOM_DIR)


.PHONY: all clean fclean re
