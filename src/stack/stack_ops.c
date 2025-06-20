#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!b || !b->top)
		return ;
	tmp = b->top;
	b->top = tmp->next;
	if (b->top)
		b->top->prev = NULL;
	else
		b->bottom = NULL;
	tmp->next = a->top;
	if (a->top)
		a->top->prev = tmp;
	else
		a->bottom = tmp;
	a->top = tmp;
	tmp->prev = NULL;
	b->size--;
	a->size++;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!a || !a->top)
		return ;
	tmp = a->top;
	a->top = tmp->next;
	if (a->top)
		a->top->prev = NULL;
	else
		a->bottom = NULL;
	tmp->next = b->top;
	if (b->top)
		b->top->prev = tmp;
	else
		b->bottom = tmp;
	b->top = tmp;
	tmp->prev = NULL;
	a->size--;
	b->size++;
	ft_putstr_fd("pb\n", 1);
}

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	a->top = second;
	if (a->bottom == second)
		a->bottom = first;

	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b || b->size < 2)
		return ;
	first = b->top;
	second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	b->top = second;
	if (b->bottom == second)
		b->bottom = first;

	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	ft_putstr_fd("ss\n", 1);
}
