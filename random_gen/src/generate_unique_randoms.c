#include "../includes/random_gen.h"

int	*generate_unique_randoms(int count)
{
	int range = RANGE_MAX - RANGE_MIN + 1;
	int *pool = malloc(sizeof(int) * range);
	if (!pool)
		return (NULL);

	for (int i = 0; i < range; i++)
		pool[i] = RANGE_MIN + i;

	for (int i = range - 1; i > 0; i--)
		ft_swap(&pool[i], &pool[rand() % (i + 1)]);

	int *result = malloc(sizeof(int) * count);
	if (!result)
		return (free(pool), NULL);

	for (int i = 0; i < count; i++)
		result[i] = pool[i];

	free(pool);
	return (result);
}
