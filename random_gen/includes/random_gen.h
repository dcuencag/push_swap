#ifndef RANDOM_GEN_H
# define RANDOM_GEN_H

# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include "../libft/libft.h"

# define RANGE_MIN -1234
# define RANGE_MAX 1234

int		*generate_unique_randoms(int count);
void	print_numbers(int *arr, int count);
void	ft_swap(int *a, int *b);

#endif
