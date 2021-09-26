#include "push_swap.h"

void	pa_or_pb(t_list **stack_a, t_list **stack_b)
{
	int	top_a;
	int	top_b;

	top_a = (*stack_a)->chislo;
	top_b = (*stack_b)->chislo;
	(*stack_a)->chislo = top_b;
	(*stack_b)->chislo = top_a;
	write(1, "s_a_or_b\n", 10);
}
