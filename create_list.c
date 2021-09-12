#include "push_swap.h"

t_list	*create_list(int argc, char **argv)
{
	int			i;
	t_list		*stack;

	i = 0;
	stack = init_list(argv[i]);
	i++;
	while (i < argc)
	{
		stack = addelem(stack, argv[i]);
		i++;
	}
	printf("%d\n", stack->chislo);
	stack = stack - 1;
	printf("%d\n", stack->chislo);
	return (stack);
}
