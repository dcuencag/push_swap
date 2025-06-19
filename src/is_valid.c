#include "../includes/push_swap.h"
#include <limits.h>

int	is_number(char *str)
{
	int	position;

	position = 0;
	if (str[position] == '-' || str[position] == '+')
		position++;
	if (!str[position])
		return (0);
	while (str[position])
	{
		if (str[position] < '0' || str[position] > '9')
			return (0);
		position++;
	}
	return (1);
}

int	is_in_int_range(char *str)
{
	long	number;
	int		sign;
	int		position;

	number = 0;
	sign = 1;
	position = 0;
	if (str[position] == '-' || str[position] == '+')
	{
		if (str[position] == '-')
			sign = -1;
		position++;
	}
	while (str[position])
	{
		number = number * 10 + (str[position] - '0');
		if ((sign == 1 && number > INT_MAX)
			|| (sign == -1 && -number < INT_MIN))
			return (0);
		position++;
	}
	return (1);
}

int	has_duplicates(int ac, char **av)
{
	int	current_index;
	int	check_index;
	int	current_value;

	current_index = 1;
	while (current_index < ac)
	{
		current_value = ft_atoi(av[current_index]);
		check_index = current_index + 1;
		while (check_index < ac)
		{
			if (ft_atoi(av[check_index]) == current_value)
				return (1);
			check_index++;
		}
		current_index++;
	}
	return (0);
}

int	is_valid(int ac, char **av)
{
	int	arg_index;

	if (ac <= 1)
		return (print_error("Insuficient number of arguments\n"));
	arg_index = 1;
	while (arg_index < ac)
	{
		if (!is_number(av[arg_index]))
			return (print_error("Invalid number in input\n"));
		if (!is_in_int_range(av[arg_index]))
			return (print_error("Number out of int range\n"));
		arg_index++;
	}
	if (has_duplicates(ac, av))
		return (print_error("Duplicated number in input\n"));
	return (1);
}
