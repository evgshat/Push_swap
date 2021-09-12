#include "push_swap.h"

void	sa_or_sb(t_list *stack)
{
	int	top;
	int	pre_top;

	if (stack == NULL)
		return ;
	if (stack->next != NULL)
	{
		while (stack->next != NULL)
			stack = (t_list *)stack->next;
	}
	top = stack->chislo;
	stack = (t_list *)stack->prev;
	if (stack == NULL)
		return ;
	pre_top = stack->chislo;
	stack->chislo = top;
	stack = (t_list *)stack->next;
	stack->chislo = pre_top;

	printf("%d\n", stack->chislo);
	stack = (t_list *)stack->prev;
	printf("%d\n", stack->chislo);
}
