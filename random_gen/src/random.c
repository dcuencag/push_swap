#include "random_gen.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./random_gen [count]\n", 2);
		return (1);
	}

	int count = ft_atoi(argv[1]);
	int range_size = RANGE_MAX - RANGE_MIN + 1;

	if (count <= 0 || count > range_size)
	{
		ft_putstr_fd("Error: count must be between 1 and ", 2);
		ft_putnbr_fd(range_size, 2);
		write(2, "\n", 1);
		return (1);
	}

	int *numbers = generate_unique_randoms(count);
	if (!numbers)
	{
		ft_putstr_fd("Memory allocation failed\n", 2);
		return (1);
	}

	print_numbers(numbers, count);
	free(numbers);
	return (0);
}
