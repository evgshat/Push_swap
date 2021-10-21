/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/16 20:07:34 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	qnty_els_is_stack(t_list **stack);
static int one_two_free_els_to_a(t_list **stack_a, t_list **stack_b, t_data *data);

int	put_in_a(t_list **stack_a, t_list **stack_b, t_data *data, int max)
{
	int		mid_order;
	t_pta *pta = NULL;
	t_list	*iterator;

	pta = init_pta(stack_b, pta);
	mid_order = (max - data->next) / 2 + data->next;
	data->flag++;
	iterator = *stack_b;
	paste_flags(iterator, data);
	while (pta->first && pta->last && !(pta->first == pta->last
			&& pta->first->order < mid_order) && !(pta->first->next == pta->last))
	{
		if (qnty_els_is_stack(stack_b) < 4)
			return (one_two_free_els_to_a(stack_a, stack_b, data));
		if (pta->first->order >= mid_order && pta->first == *stack_b)
			first_last_pta(stack_a, stack_b, data, pta, 1);
		else if (pta->last->order >= mid_order && pta->last == find_last(stack_b))
			first_last_pta(stack_a, stack_b, data, pta, 2);
		else
		{
			move_next_pta(pta, mid_order);
			if (pta->first && pta->first->order >= mid_order
					&& pta->count_for_first <= pta->count_for_last)
			{
				first_last_prev_pta(stack_a, stack_b, data, pta, 1);
				continue ;
			}
			if (pta->last && pta->last->order >= mid_order
					&& pta->count_for_last <= pta->count_for_first)
				first_last_prev_pta(stack_a, stack_b, data, pta, 2);
		}
	}
	return (find_max_order_again(stack_b));
}

static int one_two_free_els_to_a(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	qnty_els_b;

	qnty_els_b = qnty_els_is_stack(stack_b);
	if (qnty_els_b == 1)
		pa(stack_a, stack_b);
	else if (qnty_els_b == 2)
	{
		if ((*stack_b)->order < (*stack_b)->prev->order)
			sb(stack_b, 0);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else if (qnty_els_b == 3)
	{
		if ((*stack_b)->prev->order > (*stack_b)->order
			&& (*stack_b)->prev->order > (*stack_b)->prev->prev->order)
		{
			sb(stack_b, 0);
		}
		else if (((*stack_b)->prev->prev->order > (*stack_b)->prev->order
			&& (*stack_b)->prev->prev->order < (*stack_b)->order)
			|| ((*stack_b)->prev->prev->order < (*stack_b)->prev->order
				&& (*stack_b)->prev->prev->order > (*stack_b)->order))
		{
			if ((*stack_b)->prev->prev->order > (*stack_b)->prev->order
				&& (*stack_b)->prev->prev->order < (*stack_b)->order)
				sb(stack_b, 0);
			rb(stack_b, 0);
		}
		else if (((*stack_b)->prev->prev->order > (*stack_b)->prev->order
			&& (*stack_b)->prev->prev->order > (*stack_b)->order))
		{
			if ((*stack_b)->order < (*stack_b)->prev->order)
				sb(stack_b, 0);
			rb(stack_b, 0);
		}
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	top_down(stack_a, data);
	return (0);
}

static int	qnty_els_is_stack(t_list **stack)
{
	int	qnty;
	t_list	*iterator;

	qnty = 0;
	iterator = *stack;
	while (iterator != NULL)
	{
		qnty++;
		iterator = iterator->prev;
	}
	return (qnty);
}
