#include "push_swap.h"

void	sort_three_el(t_list	**stack)
{
	if ((*stack)->chislo < (*stack)->prev->chislo && (*stack)->prev->chislo  < (*stack)->prev->prev->chislo)
		return ;
	if ((*stack)->chislo < (*stack)->prev->prev->chislo)
	{
		sa(stack, 0);
		if ((*stack)->chislo > (*stack)->prev->chislo)
			ra(stack, 0);
	}
	else
	{
		ra(stack, 0);
		if ((*stack)->chislo > (*stack)->prev->chislo)
		{
			if ((*stack)->chislo > (*stack)->prev->prev->chislo)
				ra(stack, 0);
			else
				sa(stack, 0);
		}
	}
}