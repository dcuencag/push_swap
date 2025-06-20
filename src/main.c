#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;

	if (ac < 2)
		return (0);
	a = build_stack(ac, av);
	if (!a)
		return (1);
	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	radix_sort(a);
	free_stack(a);
	return (0);
}

