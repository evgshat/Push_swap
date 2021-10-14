/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_second_half.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:06:12 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/14 11:41:12 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static int already_sort(t_list **stack_a);
static int	put_in_b_again(t_list **stack_a, t_list **stack_b, t_data *data, int max, int min);
static t_list *find_last(t_list **stack_b);

void	sort_second_half(t_list **stack_a, t_list **stack_b, t_data *data, int max, int min)
{
	int	max_for_b;
	t_list	*last;
//	while (already_sort(stack_a) != 0)
//	{
		max_for_b = put_in_b_again(stack_a, stack_b, data, max, min);
		while (max_for_b > 0)
			max_for_b = put_in_a(stack_a, stack_b, data, max_for_b);
		put_in_a(stack_a, stack_b, data, max);
		while ((last = find_last(stack_a))->order != min)
			ra(stack_a, 0);
		min = (max - data->next)/2 + data->next;
//		while ((*stack_a)->order != 1)
//		{
			max_for_b = back_to_b(stack_a, stack_b);
			while (max_for_b > 0)
				max_for_b = put_in_a(stack_a, stack_b, data, max_for_b);
			while ((*stack_a)->order == data->next)
			{
				ra(stack_a, 0);
				data->next++;
			}
//		}
//	}
}

//static int already_sort(t_list **stack_a)
//{
//	t_list	*iterator;
//
//	iterator = *stack_a;
//	while (iterator->prev != NULL)
//	{
//		if (iterator->chislo > iterator->prev->chislo)
//			iterator = iterator->prev;
//		else
//			return (-1);
//	}
//	return (0);
//}

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
	res = find_max_order(stack_b);
	return (res);
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

