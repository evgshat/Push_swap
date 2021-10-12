#include "push_swap.h"

static int	write_true_false(t_list **stack_a);
static void choose_head(t_list **stack_a, int argc);

void	alg_brazh(t_list **stack_a, int argc)
{
	// int	count_true;

	choose_head(stack_a, argc);
}

static void choose_head(t_list **stack_a, int argc)
{
	t_list	*iterator;
	int		index;
	int		count_true;
	int		count_true_before;

	iterator = *stack_a;
	count_true = 0;
	count_true_before = count_true;
	iterator->head = 1;
	while ((argc - 1) >= 0)
	{
		if (count_true > count_true_before)
		{
			count_true_before = count_true;
			iterator->prev->head = 1;
		}
		if (count_true == count_true_before)
		{
			if (iterator->prev->order < iterator->prev->prev->order)
			{
				count_true_before = count_true;
				iterator->prev->prev->head = 1;
			}
		}
		count_true = 0;
		iterator = *stack_a;
		index = iterator->order;
		while ((argc - 1) >= 0)
		{
			if (iterator->order == index)
			{
				index++;
				count_true++;
				iterator->keep_a = 1;
			}
			else
				iterator->keep_a = -1;
			if (index == 7)
				index = 1;
			iterator = iterator->prev;
		}
	}
}

static int	write_true_false(t_list **stack_a)
{
	t_list	*iterator;
	int		index;
	int		count_true;

	index = 1;
	count_true = 0;
	iterator = *stack_a;
	while (iterator != NULL)
	{
		if (iterator->order == index)
		{
			index++;
			count_true++;
			iterator->keep_a = 1;
		}
		else
			iterator->keep_a = -1;
	iterator = iterator->prev;
	}
	return (count_true);
	// надо очищать итератор?
}
