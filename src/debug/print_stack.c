#include "push_swap.h"

void	print_stack(t_stack *stack, const char *name)
{
	t_node	*current;

	if (!stack)
	{
		printf("Stack %s is NULL\n", name);
		return ;
	}
	printf("Stack %s (size: %d):\n", name, stack->size);
	current = stack->top;
	while (current)
	{
		printf("  nb: %d\tindex: %d\n", current->nb, current->index);
		current = current->next;
	}
	printf("---- end of stack %s ----\n\n", name);
}
