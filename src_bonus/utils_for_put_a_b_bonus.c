/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_put_a_b_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 23:13:16 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	top_down(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while ((*stack_a)->order == data->next
		|| (*stack_a)->prev->order == data->next)
	{
		if ((*stack_a)->prev->order == data->next)
		{
			if ((*stack_b) && (*stack_b)->order < data->next)
				ss(stack_a, stack_b);
			else
				sa(stack_a);
		}
		if ((*stack_b) && (*stack_b)->order < data->next)
			rr(stack_a, stack_b);
		else
			ra(stack_a);
		data->next++;
	}
}

int	find_max_order(t_list **stack)
{
	int		max_order;
	t_list	*p;

	p = *stack;
	if (*stack == NULL)
		return (0);
	max_order = (*stack)->order;
	while (p != NULL)
	{
		if (max_order < p->order)
			max_order = p->order;
		p = p->prev;
	}
	return (max_order);
}
