#include "push_swap.h"

void	rra(t_list **stack, int is_rrr)
{
	t_list	*buf;

	if (*stack == NULL || (*stack)->prev == NULL)
		return ;
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	buf = *stack;
	*stack = NULL;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	(*stack)->next = buf;
	buf->prev = *stack;
	buf->next = NULL;
	*stack = (*stack)->next;
	if (!is_rrr)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack, int is_rrr)
{
	t_list	*buf;

	if (*stack == NULL || (*stack)->prev == NULL)
		return ;
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	buf = *stack;
	*stack = NULL;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	(*stack)->next = buf;
	buf->prev = *stack;
	buf->next = NULL;
	*stack = (*stack)->next;
	if (!is_rrr)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->prev == NULL || *stack_b == NULL || (*stack_b)->prev == NULL)
		return ;
	rra(stack_a, 1);
	rrb(stack_a, 1);
	write(1, "rrr\n", 4);
}
