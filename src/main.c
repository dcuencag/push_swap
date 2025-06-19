#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*tmp;

	if (argc < 2)
		return (1);
	if (!is_valid(argc, argv))
		return (0);
	a = build_stack(argc, argv);
	if (!a)
		return (1);
	tmp = a;
	printf("cuantity of nb = %i\n", cuantity_of_nb(a));
	printf("necesary_bits = %i\n", calculate_required_bits(cuantity_of_nb(a)));
	while (tmp)
	{
		printf("nb: %d, index: %d\n", tmp->nb, tmp->index);
		tmp = tmp->next;
	}
	free_stack(a);
	return (0);
}
