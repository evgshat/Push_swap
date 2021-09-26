#include "push_swap.h"

void	check_pa_or_pb(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b->chislo = 5;
	pa_or_pb(stack_a, &stack_b);
	printf("%d\n", (*stack_a)->chislo);
	printf("%d\n", stack_b->chislo);
}
