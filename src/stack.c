#include "../includes/push_swap.h"

t_stack	*build_stack(int argc, char **argv)
{
	int		i;
	t_stack	*head;
	t_stack	*last;
	t_stack	*node;

	i = 1;
	head = NULL;
	last = NULL;
	while (i < argc)
	{
		node = new_node(ft_atoi(argv[i]), i);
		if (!node)
			return (NULL);
		if (!head)
			head = node;
		else
		{
			last->next = node;
			node->prev = last;
		}
		last = node;
		i++;
	}
	return (head);
}

void	free_stack(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

t_stack *new_node(int nb, int index)
{
	t_stack *node = malloc(sizeof(t_stack));
	if (!node)
		return NULL;
	node->prev = NULL;
	node->nb = nb;
	node->index = index;
	node->next = NULL;
	return node;
}
