/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_second_half.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:06:12 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/16 16:20:04 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	put_in_b_again(t_list **stack_a, t_list **stack_b, t_data *data, int max, int min);
static void better_for_b(t_list **stack_a, t_list **stack_b, t_data *data);

void	sort_second_half(t_list **stack_a, t_list **stack_b, t_data *data, int max, int min)
{
	int max_for_b;
	t_list *last_a;
	int mid;

	while ((*stack_a)->order != 1)
	{
		top_down(stack_a, data);
		max_for_b = put_in_b_again(stack_a, stack_b, data, max, min);
//		better_for_b(stack_a, stack_b, data);
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
		better_for_b(stack_a, stack_b, data);
		top_down(stack_a, data);
		while (max_for_b > 0 && data->next < max)
		{
			better_for_b(stack_a, stack_b, data);
			max_for_b = put_in_a(stack_a, stack_b, data, max_for_b);
			top_down(stack_a, data);
		}
		while ((*stack_a)->order <= mid && (*stack_a)->order >= data->next
			   && data->next < max)
		{
			max_for_b = back_to_b(stack_a, stack_b, data);
			while (max_for_b > 0)
			{
				better_for_b(stack_a, stack_b, data);
				max_for_b = put_in_a(stack_a, stack_b, data, max_for_b);
				top_down(stack_a, data);
			}
		}
		min = data->next - 1;
	}
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
	while (first && last && !(first == last && first->order > mid_order)
		&& !(first->next == last))
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
			rra(stack_a, 0);
			pb(stack_a, stack_b);
			first = *stack_a;
			count_for_first = 1;
			last = find_last(stack_a);
			count_for_last = 2;
		}
		else
		{
			while (first)
			{
				if (first->order <= mid_order && first->order > min)
					break ;
				first = first->prev;
				count_for_first++;
			}
			while (last)
			{
				if (last->order <= mid_order && last->order > min )
					break ;
				last = last->next;
				count_for_last++;
			}
			if (first && first->order <= mid_order
				&& first->order > min
					&& count_for_first <= count_for_last)
			{
				while (count_for_first != 1)
				{
					if ((*stack_b) && (*stack_b)->prev != NULL && (*stack_b)->next
						!= NULL && (*stack_b)->order != data->mid_order)
						rr(stack_a, stack_b);
					else
						ra(stack_a, 0);
					count_for_first--;
				}
				pb(stack_a, stack_b);
				first = *stack_a;
				count_for_first = 1;
				last = find_last(stack_a);;
				count_for_last = 2;
				continue ;
			}
			if (last && last->order <= mid_order
				&& last->order > min
					&& count_for_last <= count_for_first)
			{
				while (count_for_last != 1)
				{
					rra(stack_a, 0);
					count_for_last--;
				}
				pb(stack_a, stack_b);
				first = *stack_a;
				last = find_last(stack_a);
				count_for_first = 1;
				count_for_last = 2;
			}
		}
	}
	res = find_max_order_again(stack_b);
	return (res);
}

static void better_for_b(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while (((*stack_b) && (*stack_b)->order == data->next)
		   || ((*stack_b) && find_last(stack_b)->order == data->next)
		   || ((*stack_b) && (*stack_b)->prev
			   && (*stack_b)->prev->order == data->next))
	{
		if ((*stack_b) && *stack_b != find_last(stack_b)
			&& find_last(stack_b)->order == data->next)
			rrb(stack_b, 0);
		else if ((*stack_b) && (*stack_b)->prev
				 && (*stack_b)->prev->order == data->next)
			sb(stack_b, 0);
		pa(stack_a, stack_b);
		ra(stack_a, 0);
		data->next++;
	}
}

