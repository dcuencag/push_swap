NAME = random_gen

SRC = src/random.c src/utils.c src/generate_unique_randoms.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
INCLUDES = -Iinclude -I$(LIBFT_DIR)

LIBFT_DIR = ../libft
LIBFT_A = $(LIBFT_DIR)/libft.a
LDFLAGS = -L$(LIBFT_DIR) -lft

all:
	@echo "\033[1;35m===================================\033[0m"
	@echo "\033[1;31m→ Checking build for random_gen...\033[0m"
	@echo "\033[1;35m===================================\033[0m"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@if [ ! -f $(NAME) ]; then \
		echo "\033[1;35m==============================\033[0m"; \
		echo "\033[1;34m→ Building random_gen tool...\033[0m"; \
		echo "\033[1;35m==============================\033[0m"; \
	fi
	@$(MAKE) -s $(NAME)
	@echo "\033[1;35m==========================================\033[0m"
	@echo "\033[1;32m✓ Random_gen build completed successfully\033[0m"
	@echo "\033[1;35m==========================================\033[0m"

$(NAME): $(OBJ)
	@echo "\033[1;35m===================================\033[0m"
	@echo "\033[1;32m→ Linking executable random_gen...\033[0m"
	@echo "\033[1;35m===================================\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LDFLAGS) -o $(NAME)
	@echo "\033[1;35m===============================\033[0m"
	@echo "\033[1;32m✓ Build completed successfully\033[0m"
	@echo "\033[1;35m===============================\033[0m"

src/%.o: src/%.c
	@echo "\033[1;34m→ Compiling $<\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re