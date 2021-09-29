#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack;
	int		res;

	res = is_chislo(argc, argv);
	if (res != 1)
		return (0);
	stack = create_list(argc, argv);
	// sa_or_sb(&stack);
	// check_pa_or_pb(&stack);
	// ra(&stack, 1);
	printf("%d\n%d\n%d\n\n", stack->chislo, stack->prev->chislo, stack->prev->prev->chislo);
	sort_three_el(&stack);
	printf("%d\n%d\n%d\n", stack->chislo, stack->prev->chislo, stack->prev->prev->chislo);
	return (0);
}

// gcc addelem.c delelem.c init_list.c is_chislo.c main.c sa_sb_ss.c utils.c create_list.c check_pa_or_pb.c pa_pb.c ra_rb_rr.c -g -o a.out