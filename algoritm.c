#include "push_swap.h"

static int	find_max_order(t_list **stack_a);
static void	put_in_b(t_list **stack_a, t_list **stack_b, int mid_order);

void	algoritm(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	mid_order;
	int	max_order;
	// написать про 5 элементов (через указатели на ф-ии ????? создать массив указателей на ф-ии)
	max_order = find_max_order(stack_a);
	mid_order = max_order/2 + data->next;
	printf("%s%d\n", "max = ", max_order);
	printf("%s%d\n", "mid = ", mid_order);
	put_in_b(stack_a, stack_b, mid_order);
}


static int	find_max_order(t_list **stack_a)
{
	int		max_order;
	t_list	*p;

	p = *stack_a;
	max_order = 0;
	while (p->prev != NULL)
	{
		max_order++;
		p = p->prev;
	}
	max_order++;
	return (max_order);
}

static void	put_in_b(t_list **stack_a, t_list **stack_b, int mid_order)
{
	t_list	*p;

	while (mid_order >= 1)
	{
		p = *stack_a;
		while(p->order != mid_order)
			p = p->prev;
		if (p->order == mid_order)
		{
			pb(stack_a, stack_b);
			mid_order--;
		}
	}
}