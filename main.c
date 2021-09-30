#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		res;

	res = is_chislo(argc, argv);
	if (res != 1)
		return (0);
	stack_a = create_list(argc, argv);
	stack_b = init_list("0");
	// sa_or_sb(&stack);
	// check_pa_or_pb(&stack);
	// ra(&stack, 1);
	// printf("%d\n%d\n%d\n\n",stack->chislo, stack->prev->chislo, stack->prev->prev->chislo);
	// sort_three_el(&stack);
	// printf("%d\n%d\n%d\n", stack->chislo, stack->prev->chislo, stack->prev->prev->chislo);
	sort_four_el(&stack_a, &stack_b);
	while (stack_a != NULL)
	{
		printf("%d\n", stack_a->chislo);
		stack_a = stack_a->prev;
	}
	return (0);
}

// gcc addelem.c delelem.c init_list.c is_chislo.c main.c sa_sb_ss.c utils.c create_list.c check_pa_or_pb.c pa_pb.c ra_rb_rr.c -g -o a.out