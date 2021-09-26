#include "push_swap.h"

t_list	*create_list(int argc, char **argv)
{
	int			i;
	t_list		*stack;

	i = 1;
	stack = init_list(argv[i]);
	i++;
	while (i < argc)
	{
		stack = addelem(&stack, argv[i]);
		i++;
	}
	printf("%d\n", stack->chislo);
	printf("%s\n", "end of create list");
	return (stack);
}

// gcc addelem.c delelem.c init_list.c is_chislo.c main.c sa_or_sb.c ss.c utils.c create_list.c -g -o a.out