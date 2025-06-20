#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <limits.h>

// ======================= STRUCTURES ======================= //

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				nb;
	int				index;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

// ========================= INIT ========================== //

t_stack	*init_stack(void);
t_node	*new_node(int nb);
void	push_back(t_stack *stack, t_node *new);
void	free_stack(t_stack *stack);

// ========================= PARSER ======================== //

t_stack	*build_stack(int ac, char **av);

// ======================== UTILS ========================== //

int		is_number(char *str);
int		is_in_int_range(char *str);
int		stack_contains(t_stack *stack, int nb);
long	ft_atol(char *str);
int		is_sorted(t_stack *stack);
void	free_split(char **split);

// ========================= DEBUG ========================= //

void	print_stack(t_stack *stack, const char *name);

// ======================= OPERATIONS ======================= //

// Push / Swap / Rotate / Reverse

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// ======================== ALGORITHM ======================= //

void	assign_indexes(t_stack *stack);
void	radix_sort(t_stack *a);

void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	sort_small(t_stack *a);

#endif
