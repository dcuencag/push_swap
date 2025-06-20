#include "../../include/push_swap.h"

void	assign_indexes(t_stack *stack)
{
	t_node	*curr;
	t_node	*cmp;
	int		index;

	curr = stack->top;
	while (curr)
	{
		index = 0;
		cmp = stack->top;
		while (cmp)
		{
			if (cmp->nb < curr->nb)
				index++;
			cmp = cmp->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}

static void	radix_loop(t_stack *a, t_stack *b, int max_bits, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if ((a->top->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (b->size)
			pa(a, b);
	}
}

static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a)
{
	t_stack	*b;
	int		size;
	int		max_bits;

	b = init_stack();
	if (!b)
		return ;
	assign_indexes(a);
	size = a->size;
	max_bits = get_max_bits(size);
	radix_loop(a, b, max_bits, size);
	free_stack(b);
}