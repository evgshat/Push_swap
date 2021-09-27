#include "push_swap.h"

void	check_pa_or_pb(t_list **stack_a)
{
	t_list	*stack_b;

	pa(stack_a, &stack_b);
	printf("%s", "stack a = ");
	printf("%d\n", (*stack_a)->chislo);
	printf("%s", "stack b = ");
	printf("%d\n", stack_b->chislo);
}
