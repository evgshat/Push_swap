#include "push_swap.h"

static t_list *find_last(t_list **stack_b);
static int	find_max_order_again(t_list **stack);

int	put_in_a(t_list **stack_a, t_list **stack_b, t_data *data, int max)
{
	t_list	*first;
	t_list	*last;
	int		count_for_first;
	int		count_for_last;
	int		mid_order;
	int		res;
	t_list	*iterator;

	mid_order = (max - data->next) / 2 + data->next;
//	res = max - mid_order - 1;
	data->flag++;
	count_for_first = 1;
	count_for_last = 2;
	first = *stack_b;
	last = find_last(stack_b);
	iterator = *stack_b;
	while (iterator != NULL)
	{
		iterator->flag = data->flag;
		iterator = iterator->prev;
	}

	while (first && last && !(first == last && first->order < mid_order) && !(first->next == last))
	{
		if (first->order >= mid_order && first == *stack_b)
		{
			pa(stack_a, stack_b);
			if ((*stack_a)->order == data->next)
			{
				ra(stack_a, 0);
				data->next++;
			}
			first = *stack_b;
			count_for_first = 1;
			last = find_last(stack_b);
			count_for_last = 2;
		}
		else if (last->order >= mid_order && last == find_last(stack_b))
		{
			last = last->next;
			count_for_last = 2;
			rrb(stack_b, 0);
			pa(stack_a, stack_b);
			if ((*stack_a)->order == data->next)
			{
				ra(stack_a, 0);
				data->next++;
			}
			first = *stack_b;
			count_for_first = 1;
		}
		else
		{
			first = first->prev;
			count_for_first++;
			if (first && first->order >= mid_order && count_for_first <= count_for_last)
			{
				while (count_for_first != 1)
				{
					if (count_for_first == 2 && (count_for_first == 2 && first->prev && first->prev->prev && first->prev->prev->order > mid_order))
						sb(stack_b, 0);
					else if (count_for_first != 2 || (count_for_first == 2 && first->prev && first->prev->prev && first->prev->prev->order <= mid_order))
					{
						rb(stack_b, 0);
						last = last->prev;
						count_for_last = 2;
					}
					count_for_first--;
				}
				pa(stack_a, stack_b);
				if ((*stack_a)->order == data->next)
				{
					ra(stack_a, 0);
					data->next++;
				}
				first = *stack_b;
				count_for_first = 1;
				continue ;
			}
			last = last->next;
			count_for_last++;
			if (last && last->order >= mid_order && count_for_last <= count_for_first)
			{
				while (count_for_last != 1)
				{
					rrb(stack_b, 0);
					count_for_last--;
				}
				pa(stack_a, stack_b);
				if ((*stack_a)->order == data->next)
				{
					ra(stack_a, 0);
					data->next++;
				}
				first = *stack_b;
				last = last->next;
				count_for_first = 1;
				count_for_last = 2;
			}
		}
	}
	res = find_max_order_again(stack_b);
	return (res);
}

static int	find_max_order_again(t_list **stack)
{
	int		max_order;
	t_list	*p;

	if (*stack == NULL)
		return (0);
	p = *stack;
	max_order = p->order;
	while (p != NULL)
	{
		if (p->order > max_order)
			max_order = p->order;
		p = p->prev;
	}
	return (max_order);
}

static t_list *find_last(t_list **stack_b)
{
	t_list	*last;

	last = *stack_b;
	if (!last)
		return NULL;
	while (last->prev != NULL)
		last = last->prev;
	return (last);
}

// int	algoritm_path_two(t_list **stack_a, t_list **stack_b, t_data *data, int max)
// {
// 	int		mid_order;
// 	t_list	*p;
// 	t_list	*iterator;
// 	int		i;
// 	int		res;

// 	mid_order = (max - data->next) / 2 + data->next;
// 	res = max - mid_order - 1;
// 	data->flag++;
// 	while (max >= mid_order)
// 	{
// 		p = *stack_b;
// 		while(p->order != mid_order)
// 			p = p->prev;
// 		if (p->order == mid_order)
// 		{
// 			i = 1;
// 			iterator = *stack_b;
// 			while (iterator->order != mid_order)
// 			{
// 				i++;
// 				iterator = iterator->prev;
// 			}
// 			if (i >= mid_order)
// 				shift_rra(stack_b, max, i);
// 			else
// 				shift_ra(stack_b, i);
// 			pa(stack_a, stack_b);
// 			if (iterator->order == data->next)
// 			{
// 				ra(stack_a, 0);
// 				data->next++;
// 			}
// 		}
// 		mid_order++;
// 	}
// 	return (res);
// }