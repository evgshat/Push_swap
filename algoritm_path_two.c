#include "push_swap.h"

static void	shift_rra(t_list **stack_a, int max, int iterator);
static void	shift_ra(t_list **stack_a, int iterator);

int	algoritm_path_two(t_list **stack_a, t_list **stack_b, t_data *data, int max)
{
	int		mid_order;
	t_list	*p;
	t_list	*iterator;
	int		i;
	int		res;

	mid_order = (max - data->next) / 2 + data->next;
	res = max - mid_order - 1;
	data->flag++;
	while (max >= mid_order)
	{
		p = *stack_b;
		while(p->order != mid_order)
			p = p->prev;
		if (p->order == mid_order)
		{
			i = 1;
			iterator = *stack_b;
			while (iterator->order != mid_order)
			{
				i++;
				iterator = iterator->prev;
			}
			if (i >= mid_order)
				shift_rra(stack_b, max, i);
			else
				shift_ra(stack_b, i);
			pa(stack_a, stack_b);
			if (iterator->order == data->next)
			{
				ra(stack_a, 0);
				data->next++;
			}
		}
		mid_order++;
	}
	return (res);
}

static void	shift_rra(t_list **stack_a, int max, int iterator)
{
	while(max >= iterator)
	{
		rra(stack_a, 0);
		max--;
	}
}

static void	shift_ra(t_list **stack_a, int iterator)
{
	while (iterator > 1)
	{
		ra(stack_a, 0);
		iterator--;
	}
}

// printf("%s\n", "stack_a =");
	// while (*stack_a != NULL)
	// {
	// 	printf("%d\n", (*stack_a)->chislo);
	// 	*stack_a = (*stack_a)->prev;
	// }
	// printf("%s\n", "stack_b =");

	// while (*stack_b != NULL)
	// {
	// 	printf("%d\n", (*stack_b)->chislo);
	// 	*stack_b = (*stack_b)->prev;
	// }