#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	struct s_stack *prev;
	int nb;
	int index;
	struct s_stack *next;
}	t_stack;

int		main(int ac, char **av);
int		is_valid(int ac, char **av);
int		print_error(char *error);
int		cuantity_of_nb(t_stack *a);
int		calculate_required_bits(int max_value);
t_stack	*build_stack(int argc, char **argv);
void	free_stack(t_stack *stack);
t_stack *new_node(int nb, int index);

#endif