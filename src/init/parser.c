#include "push_swap.h"

static int	is_valid_number(char *str)
{
	return (is_number(str) && is_in_int_range(str));
}

static int	fill_stack(t_stack *stack, char **numbers)
{
	int		i;
	long	num;
	t_node	*new;

	i = 0;
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i]))
			return (0);
		num = ft_atol(numbers[i]);
		if (stack_contains(stack, (int)num))
			return (0);
		new = new_node((int)num);
		if (!new)
			return (0);
		push_back(stack, new);
		i++;
	}
	return (1);
}

t_stack	*build_stack(int ac, char **av)
{
	t_stack	*stack;
	char	**numbers;
	int		success;

	stack = init_stack();
	if (!stack)
		return (NULL);
	if (ac == 2)
		numbers = ft_split(av[1], ' ');
	else
		numbers = &av[1];
	success = fill_stack(stack, numbers);
	if (ac == 2)
		free_split(numbers);
	if (!success)
	{
		free_stack(stack);
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	return (stack);
}
