#include "push_swap.h"

void	sort_two_el(t_list	**stack)
{
	if ((*stack)->chislo > (*stack)->prev->chislo)
	{
		sa(stack, 0);
	}
}

// void	sort_two_el(t_list	**stack)
// {
// 	if ((*stack)->chislo > (*stack)->prev->chislo)
// 	{
// 		(*stack)->next = (*stack)->prev;
// 		(*stack)->prev->prev = *stack;
// 		(*stack)->prev = NULL;
// 		(*stack)->next->next = NULL;
// 		*stack = (*stack)->next;
// 	}
// }
