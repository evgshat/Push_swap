#include "push_swap.h"

void	sort_three_el(t_list	**stack)
{
	if ((*stack)->chislo < (*stack)->prev->chislo && (*stack)->prev->chislo  < (*stack)->prev->prev->chislo)
		return ;
	if ((*stack)->chislo < (*stack)->prev->prev->chislo)
	{
		sa(stack, 0);
		if ((*stack)->chislo > (*stack)->prev->chislo)
			rra(stack, 0);
	}
	else
	{
		rra(stack, 0);
		if ((*stack)->chislo > (*stack)->prev->chislo)
		{
			if ((*stack)->chislo > (*stack)->prev->prev->chislo)
				rra(stack, 0);
			else
				sa(stack, 0);
		}
	}
}