#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	struct s_node *prev;
	struct s_node *next;
	int nb;
	int index;
}	t_node;

typedef struct s_stack
{
	t_node *top;
	t_node *bottom;
	int size;
}	t_stack;

int		main(int ac, char **av);


#endif