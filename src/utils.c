#include "../includes/push_swap.h"

int	print_error(char *error)
{
		ft_putstr_fd(error, 2);
		return (0);
}

int calculate_required_bits(int max_value)
{
    int bits = 0;
    while ((1 << bits) <= max_value)
        bits++;
    return bits;
}

int	cuantity_of_nb(t_stack *a)
{
	int i = 0;

	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}
