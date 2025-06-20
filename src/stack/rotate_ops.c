#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*last;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	a->top = first->next;
	a->top->prev = NULL;

	last = a->bottom;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	a->bottom = first;

	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b)
{
	t_node	*first;
	t_node	*last;

	if (!b || b->size < 2)
		return ;
	first = b->top;
	b->top = first->next;
	b->top->prev = NULL;

	last = b->bottom;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	b->bottom = first;

	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_stack *a)
{
	t_node	*last;

	if (!a || a->size < 2)
		return ;
	last = a->bottom;
	a->bottom = last->prev;
	a->bottom->next = NULL;

	last->next = a->top;
	last->prev = NULL;
	a->top->prev = last;
	a->top = last;

	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b)
{
	t_node	*last;

	if (!b || b->size < 2)
		return ;
	last = b->bottom;
	b->bottom = last->prev;
	b->bottom->next = NULL;

	last->next = b->top;
	last->prev = NULL;
	b->top->prev = last;
	b->top = last;

	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	ft_putstr_fd("rrr\n", 1);
}