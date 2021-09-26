#include "push_swap.h"

void	ra(t_list **stack, int is_rr)
{
	t_list	*buf;
	t_list	*iterator;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	buf = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	iterator = *stack;
	while (iterator->next != NULL)
		iterator = iterator->next;
	iterator->next = buf;
	buf->prev = iterator;
	buf->next = NULL;
	if (!is_rr)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack, int is_rr)
{
	t_list	*buf;
	t_list	*iterator;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	buf = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	iterator = *stack;
	while (iterator->next != NULL)
		iterator = iterator->next;
	iterator->next = buf;
	buf->prev = iterator;
	buf->next = NULL;
	if (!is_rr)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	ra(stack_a, 1);
	rb(stack_b, 1);
	write(1, "rr\n", 3);
}
