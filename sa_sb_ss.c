#include "push_swap.h"

void	sa(t_list **stack, int is_ss)
{
	int	ch_top;
	int	ch_top_minus;

	ch_top = (*stack)->chislo;
	*stack = (*stack)->prev;
	ch_top_minus = (*stack)->chislo;
	(*stack)->chislo = ch_top;
	*stack = (*stack)->next;
	(*stack)->chislo = ch_top_minus;
	if (!is_ss)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack, int is_ss)
{
	int	ch_top;
	int	ch_top_minus;

	ch_top = (*stack)->chislo;
	*stack = (*stack)->prev;
	ch_top_minus = (*stack)->chislo;
	(*stack)->chislo = ch_top;
	*stack = (*stack)->next;
	(*stack)->chislo = ch_top_minus;
	if (!is_ss)
		write(1, "sa\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	write(1, "ss\n", 3);
}
