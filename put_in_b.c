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

static void	clear_last_el_in_b(t_list **stack_b);

void	put_in_b(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_pta *ptb = NULL;

	ptb = init_pta(stack_b, ptb);
	while (ptb->first && ptb->last && !(ptb->first == ptb->last && ptb->first->order > data->mid_order)
		   && ptb->first->next != ptb->last)
	{
		if (ptb->first->order <= data->mid_order && ptb->first == *stack_a)
			first_last_ptb(stack_a, stack_b, ptb, 1);
		else if (ptb->last->order <= data->mid_order && ptb->last == find_last(stack_a))
			first_last_ptb(stack_a, stack_b, ptb, 2);
		else
		{
			move_next_ptb(ptb, data);
			if (ptb->first && ptb->first->order <= data->mid_order
				&& ptb->count_for_first <= ptb->count_for_last)
			{
				first_last_prev_ptb(stack_a, stack_b, ptb, 1);
				continue ;
			}
			if (ptb->last && ptb->last->order <= data->mid_order
				&& ptb->count_for_last <= ptb->count_for_first)
				first_last_prev_ptb(stack_a, stack_b, ptb, 2);
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
