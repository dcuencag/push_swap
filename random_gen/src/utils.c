#include "../includes/random_gen.h"

void	ft_swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print_numbers(int *arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		char *str = ft_itoa(arr[i]);
		if (!str)
			continue;
		ft_putstr_fd(str, 1);
		if (i < count - 1)
			ft_putchar_fd(' ', 1);
		free(str);
	}
	ft_putchar_fd('\n', 1);
}
