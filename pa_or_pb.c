#include "push_swap.h"

void	pa_or_pb(t_list *stack_a, t_list *stack_b)
{
	int	top_a;
	int top_b;
	if (stack_a->next != NULL)
	{
		while (stack_a->next != NULL)
			stack_a = (t_list *)stack_a->next;
	}
	if (stack_b->next != NULL)
	{
		while (stack_b->next != NULL)
			stack_b = (t_list *)stack_b->next;
	}
	top_a = stack_a->chislo;
	top_b = stack_b->chislo;
	stack_a->chislo = top_b;
	stack_b->chislo = top_a;
}