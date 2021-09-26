#include "push_swap.h"

void	sa_or_sb(t_list **stack)
{
	int	ch_top;
	int	ch_top_minus;

	ch_top = (*stack)->chislo;
	*stack = (*stack)->prev;
	ch_top_minus = (*stack)->chislo;
	(*stack)->chislo = ch_top;
	*stack = (*stack)->next;
	(*stack)->chislo = ch_top_minus;
	write(1, "s_a_or_b\n", 10);
}
