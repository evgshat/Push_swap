/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_second_half.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:06:12 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/15 20:43:39 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	put_in_b_again(t_list **stack_a, t_list **stack_b, t_data *data, int max, int min);
static t_list *find_last(t_list **stack_b);
static int	find_max_order_again(t_list **stack);

void	sort_second_half(t_list **stack_a, t_list **stack_b, t_data *data, int max, int min)
{
	int max_for_b;
	t_list *last_a;
	int mid;

//	while ((*stack_a)->order != 1)
//	{
		max_for_b = put_in_b_again(stack_a, stack_b, data, max, min);
		mid = max_for_b;
		last_a = find_last(stack_a);
		while (last_a->order > min && data->next < max)
		{
			if ((*stack_b) && (*stack_b)->order != data->next)
				rrr(stack_a, stack_b);
			else
				rra(stack_a, 0);
			last_a = find_last(stack_a);
		}
		while ((*stack_b) && (*stack_b)->order == data->next)
		{
			pa(stack_a, stack_b);
			ra(stack_a, 0);
			data->next++;
	//			continue;
		}
		while (max_for_b > 0 && data->next < max)
		{
			max_for_b = put_in_a(stack_a, stack_b, data, max_for_b);
			top_down(stack_a, data);
		}
		while ((*stack_a)->order <= mid && (*stack_a)->order >= data->next
			   && data->next < max)
		{
			max_for_b = back_to_b(stack_a, stack_b);
			while (max_for_b > 0)
			{
				max_for_b = put_in_a(stack_a, stack_b, data, max_for_b);
				top_down(stack_a, data);
			}
		}
//		min = data->next - 1;

//	}
}

static int	find_max_order_again(t_list **stack)
{
	int		max_order;
	t_list	*p;

	p = *stack;
	if (*stack == NULL)
		return (0);
	max_order = p->order;
	while (p != NULL)
	{
		if (p->order > max_order)
			max_order = p->order;
		p = p->prev;
	}
	return (max_order);
}

static int	put_in_b_again(t_list **stack_a, t_list **stack_b, t_data *data, int max, int min)
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
	first = *stack_a;
	last = find_last(stack_a);
	iterator = *stack_a;
	while (iterator != NULL)
	{
		iterator->flag = data->flag;
		iterator = iterator->prev;
	}
	// если наверху в а есть дата-некст, то сразу вниз
//	while ((*stack_a)->order == data->next)
//	{
//		if ((*stack_a)->order == data->next)
//			ra(stack_a, 0);
//		data->next++;
//	}

	while (first && last && !(first == last && first->order > mid_order) && !(first->next == last))
	{
		if (first->order <= mid_order && first->order > min && first == *stack_a)
		{
			pb(stack_a, stack_b);
			first = *stack_a;
			count_for_first = 1;
			last = find_last(stack_a);
			count_for_last = 2;
		}
		else if (last->order <= mid_order && last->order > min && last == find_last(stack_a))
		{
			last = last->next;
			count_for_last = 2;
			rra(stack_a, 0);
			pb(stack_a, stack_b);
			first = *stack_a;
			count_for_first = 1;
		}
		else
		{
			first = first->prev;
			count_for_first++;
			if (first && first->order <= mid_order && first->order > min && count_for_first <= count_for_last)
			{
				while (count_for_first != 1)
				{
					if (count_for_first == 2 && (count_for_first == 2 && first->prev && first->prev->prev && first->prev->prev->order > mid_order))
						sa(stack_a, 0);
					else if (count_for_first != 2 || (count_for_first == 2 && first->prev && first->prev->prev && first->prev->prev->order <= mid_order))
					{
						ra(stack_a, 0);
						last = last->prev;
						count_for_last = 2;
					}
					count_for_first--;
				}
				pb(stack_a, stack_b);
				first = *stack_a;
				count_for_first = 1;
				continue ;
			}
			last = last->next;
			count_for_last++;
			if (last && last->order <= mid_order && last->order > min && count_for_last <= count_for_first)
			{
				while (count_for_last != 1)
				{
					rra(stack_a, 0);
					count_for_last--;
				}
				pb(stack_a, stack_b);
				first = *stack_a;
				last = last->next;
				count_for_first = 1;
				count_for_last = 2;
			}
		}
	}
	res = find_max_order_again(stack_b);
	return (res);
}

static t_list *find_last(t_list **stack)
{
	t_list	*last;

	last = *stack;
	if (!last)
		return NULL;
	while (last->prev != NULL)
		last = last->prev;
	return (last);
}

