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
	stack = (t_list *)stack->prev;
	printf("%d\n", stack->chislo);
	// stack = stack->prev;
	return (stack);
}
