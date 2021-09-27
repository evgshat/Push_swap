#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*buf;

	buf = *stack_a;
	*stack_a = (*stack_a)->prev;
	(*stack_a)->next = NULL;
	(*stack_b)->next = malloc(sizeof(t_list));
	(*stack_b)->next->chislo = buf->chislo;
	(*stack_b)->next->next = NULL;
	(*stack_b)->next->prev = *stack_b;
	*stack_b = (*stack_b)->next;
	free (buf);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*buf;

	buf = *stack_b;
	*stack_b = (*stack_b)->prev;
	(*stack_b)->next = NULL;
	(*stack_a)->next = malloc(sizeof(t_list));
	(*stack_a)->next->chislo = buf->chislo;
	(*stack_a)->next->next = NULL;
	(*stack_a)->next->prev = *stack_b;
	*stack_a = (*stack_a)->next;
	free (buf);
	write(1, "pb\n", 3);
}
