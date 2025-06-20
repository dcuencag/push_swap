#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	int	first;
	int	second;

	if (stack->size != 2)
		return ;
	first = stack->top->nb;
	second = stack->top->next->nb;
	if (first > second)
		sa(stack);
}

void	sort_three(t_stack *stack)
{
	int	a = stack->top->nb;
	int	b = stack->top->next->nb;
	int	c = stack->bottom->nb;

	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

static int	get_min_pos(t_stack *stack)
{
	t_node	*current = stack->top;
	t_node	*min_node = current;
	int		pos = 0;
	int		min_pos = 0;

	while (current)
	{
		if (current->nb < min_node->nb)
		{
			min_node = current;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min_pos = get_min_pos(a);

	if (min_pos <= a->size / 2)
		while (min_pos-- > 0)
			ra(a);
	else
		while (min_pos++ < a->size)
			rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_pos = get_min_pos(a);

	if (min_pos <= a->size / 2)
		while (min_pos-- > 0)
			ra(a);
	else
		while (min_pos++ < a->size)
			rra(a);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void	sort_small(t_stack *a)
{
	t_stack	*b = init_stack();

	if (!b)
		return ;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	free_stack(b);
}
