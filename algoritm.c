#include "push_swap.h"

static int	find_max_order(t_list **stack_a);
static void	put_in_b(t_list **stack_a, t_list **stack_b, int mid_order, int max);
static void	shift_rra(t_list **stack_a, int max, int iterator);
static void	shift_ra(t_list **stack_a, int iterator);
static void	main_shift_ra(t_list **stack_a, int mid_order, int max_order);
static void	clear_last_el_in_b(t_list **stack_b);

void	algoritm(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	mid_order;
	int	max_order;
	// написать про 5 элементов (через указатели на ф-ии ????? создать массив указателей на ф-ии)
	max_order = find_max_order(stack_a);
	mid_order = max_order/2 + data->next;
	// printf("%s%d\n", "max = ", max_order);
	// printf("%s%d\n", "mid = ", mid_order);
	put_in_b(stack_a, stack_b, mid_order, max_order);
	main_shift_ra(stack_a, mid_order, max_order);
	while (mid_order >= 0)
		mid_order = algoritm_path_two(stack_a, stack_b, data, mid_order);
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

static void	put_in_b(t_list **stack_a, t_list **stack_b, int mid_order, int max)
{
	t_list	*p;
	t_list	*iterator;
	int		i;

	while (mid_order >= 1)
	{
		p = *stack_a;
		while(p->order != mid_order)
			p = p->prev;
		if (p->order == mid_order)
		{
			i = 1;
			iterator = *stack_a;
			while (iterator->order != mid_order)
			{
				i++;
				iterator = iterator->prev;
			}
			if (i >= mid_order)
				shift_rra(stack_a, max, i);
			else
				shift_ra(stack_a, i);
			pb(stack_a, stack_b);
		}
		mid_order--;
		max--;
	}
	clear_last_el_in_b(stack_b);
}

static void	shift_rra(t_list **stack_a, int max, int iterator)
{
	while (max >= iterator)
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

static void	main_shift_ra(t_list **stack_a, int mid_order, int max_order)
{
	while (mid_order <= max_order)
	{
		ra(stack_a, 0);
		mid_order++;
	}
}

static void	clear_last_el_in_b(t_list **stack_b)
{
	while ((*stack_b)->prev != NULL)
		*stack_b = (*stack_b)->prev;
	(*stack_b)->next->prev = NULL;
	while ((*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
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