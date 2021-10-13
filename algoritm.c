/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/13 21:50:21 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_in_b(t_list **stack_a, t_list **stack_b, int mid_order);
static void less_six (t_list **stack_a, t_list **stack_b, t_data *data);
static void	clear_last_el_in_b(t_list **stack_b);
static t_list *find_last(t_list **stack_a);
//static int	put_in_a_again(t_list **stack_a, t_list **stack_b, t_data *data, int max);

void	algoritm(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	mid_order;
	int	max_order;
	int	max_for_b;

	if (data->argc < 7)
	{
		less_six(stack_a, stack_b, data);
		return ;
	}
	max_order = find_max_order(stack_a);
	mid_order = max_order/2 + data->next;
	max_for_b = mid_order;
	put_in_b(stack_a, stack_b, mid_order);
	while (max_for_b > 0)
		max_for_b = put_in_a(stack_a, stack_b, data, max_for_b);
	while ((*stack_a)->order == data->next)
	{
		ra(stack_a, 0);
		data->next++;
	}
	while ((*stack_a)->flag != 0)
	{
		max_for_b = back_to_b(stack_a, stack_b);
		while (max_for_b > 0)
			max_for_b = put_in_a(stack_a, stack_b, data, max_for_b);
		while ((*stack_a)->order == data->next)
		{
			ra(stack_a, 0);
			data->next++;
		}
	}
	sort_second_half(stack_a, stack_b, data, max_order);
		//
//	max_for_b = back_to_b(stack_a, stack_b);
//	while (max_for_b > 0)
//		max_for_b = put_in_a_again(stack_a, stack_b, data, max_for_b);
//	while ((*stack_a)->order == data->next)
//	{
//		ra(stack_a, 0);
//		data->next++;
//	}
	//
//	max_for_b = back_to_b(stack_a, stack_b);
//	while (max_for_b > 0)
//		max_for_b = put_in_a_again(stack_a, stack_b, data, max_for_b);
//	while ((*stack_a)->order == data->next)
//	{
//		ra(stack_a, 0);
//		data->next++;
//	}


}

int	find_max_order(t_list **stack_a)
{
	int		max_order;
	t_list	*p;

	p = *stack_a;
	max_order = 0;
	if (*stack_a == NULL)
		return (0);
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
	t_list	*first;
	t_list	*last;
	int		count_for_first;
	int		count_for_last;

	count_for_first = 1;
	count_for_last = 2;
	first = *stack_a;
	last = find_last(stack_a);
	while (!(first == last && first->order > mid_order) && !(first->next == last))
	{
		if (first->order <= mid_order && first == *stack_a)
		{
			pb(stack_a, stack_b);
			first = *stack_a;
			count_for_first = 1;
		}
		else if (last->order <= mid_order && last == find_last(stack_a))
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
			if (first->order <= mid_order && count_for_first <= count_for_last)
			{
				while (count_for_first != 1)
				{
					if (count_for_first == 2 && first->prev
						&& first->prev->prev
						&& first->prev->prev->order > mid_order)
						sa(stack_a, 0); // или ra
					else if (count_for_first != 2
						|| (count_for_first == 2 && first->prev
							&& first->prev->prev
							&& first->prev->prev->order <= mid_order))
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
			if (last->order <= mid_order && count_for_last <= count_for_first)
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
	clear_last_el_in_b(stack_b);
}

static void	clear_last_el_in_b(t_list **stack_b)
{
	while ((*stack_b)->prev != NULL)
		*stack_b = (*stack_b)->prev;
	(*stack_b)->next->prev = NULL;
	while ((*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
}

static t_list *find_last(t_list **stack_a)
{
	t_list	*last;

	if (*stack_a == NULL)
		return (0);
	last = *stack_a;
	while (last->prev != NULL)
		last = last->prev;
	return (last);
}

static void less_six (t_list **stack_a, t_list **stack_b, t_data *data)
{
	void (*funcs_1) (t_list **stack_a);
	void (*funcs_2) (t_list **stack_a, t_list **stack_b);

	if (data->argc < 7)
	{
		if (data->argc == 3)
		{
			funcs_1 = sort_two_el;
			funcs_1(stack_a);
		}
		else if (data->argc == 4)
		{
			funcs_1 = sort_three_el;
			funcs_1(stack_a);
		}
		else if (data->argc == 5)
		{
			funcs_2 = sort_four_el;
			funcs_2(stack_a, stack_b);
		}
		else if (data->argc == 6)
		{
			funcs_2 = sort_five_el;
			funcs_2(stack_a, stack_b);
		}
		return ;
	}
}

//static int	put_in_a_again(t_list **stack_a, t_list **stack_b, t_data *data, int max)
//{
//	t_list	*first;
//	t_list	*last;
//	int		count_for_first;
//	int		count_for_last;
//	int		mid_order;
//	int		res;
//	t_list	*iterator;
//
//	mid_order = (max - data->next) / 2 + data->next;
////	res = max - mid_order - 1;
//	count_for_first = 1;
//	count_for_last = 2;
//	first = *stack_b;
//	last = find_last(stack_b);
//	iterator = *stack_b;
//	while (first && last && !(first == last && first->order < mid_order) && !(first->next == last))
//	{
//		if (first->order >= mid_order && first == *stack_b)
//		{
//			pa(stack_a, stack_b);
//			if ((*stack_a)->order == data->next)
//			{
//				ra(stack_a, 0);
//				data->next++;
//			}
//			first = *stack_b;
//			count_for_first = 1;
//			last = find_last(stack_b);
//			count_for_last = 2;
//		}
//		else if (last->order >= mid_order && last == find_last(stack_b))
//		{
//			last = last->next;
//			count_for_last = 2;
//			rrb(stack_b, 0);
//			pa(stack_a, stack_b);
//			if ((*stack_a)->order == data->next)
//			{
//				ra(stack_a, 0);
//				data->next++;
//			}
//			first = *stack_b;
//			count_for_first = 1;
//		}
//		else
//		{
//			first = first->prev;
//			count_for_first++;
//			if (first && first->order >= mid_order && count_for_first <= count_for_last)
//			{
//				while (count_for_first != 1)
//				{
//					if (count_for_first == 2)
//						sb(stack_b, 0);
//					else if (count_for_first != 2 || (count_for_first == 2 && first->prev && first->prev->prev && first->prev->prev->order <= mid_order))
//					{
//						rb(stack_b, 0);
//						last = last->prev;
//						count_for_last = 2;
//					}
//					count_for_first--;
//				}
//				pa(stack_a, stack_b);
//				if ((*stack_a)->order == data->next)
//				{
//					ra(stack_a, 0);
//					data->next++;
//				}
//				first = *stack_b;
//				count_for_first = 1;
//				continue ;
//			}
//			last = last->next;
//			count_for_last++;
//			if (last && last->order >= mid_order && count_for_last <= count_for_first)
//			{
//				while (count_for_last != 1)
//				{
//					rrb(stack_b, 0);
//					count_for_last--;
//				}
//				pa(stack_a, stack_b);
//				if ((*stack_a)->order == data->next)
//				{
//					ra(stack_a, 0);
//					data->next++;
//				}
//				first = *stack_b;
//				last = last->next;
//				count_for_first = 1;
//				count_for_last = 2;
//			}
//		}
//	}
//	res = find_max_order(stack_b);
//	return (res);
//}
