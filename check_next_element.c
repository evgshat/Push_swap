/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:38:41 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/20 00:12:26 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_next_element_two(t_list **stack_a,
				t_list **stack_b, t_data *data);

int	check_next_element(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	res;

	res = 2;
	res = check_next_element_two(stack_a, stack_b, data);
	if (res == 1)
		return (1);
	if (res == 0)
		return (0);
	(*stack_b)->flag = data->flag;
	pa(stack_a, stack_b);
	if ((*stack_b) && (*stack_b)->order < data->next)
		rr(stack_a, stack_b);
	else
		ra(stack_a, 0);
	data->next++;
	return (1);
}

static int	check_next_element_two(t_list **stack_a,
				t_list **stack_b, t_data *data)
{
	if ((*stack_b) && (*stack_b)->order == data->next)
	{
		(*stack_b)->flag = data->flag;
		pa(stack_a, stack_b);
		if (*stack_b && (*stack_b)->order < data->next)
			rr(stack_a, stack_b);
		else
			ra(stack_a, 0);
		data->next++;
		return (1);
	}
	else if ((*stack_b) && (*stack_b)->prev
		&& (*stack_b)->prev->order == data->next)
		sb(stack_b, 0);
	else if ((*stack_b) && find_last(stack_b)->order == data->next)
		rrb(stack_b, 0);
	else if (*stack_b && find_last(stack_b)->next
		&& find_last(stack_b)->next->order == data->next)
	{
		rrb(stack_b, 0);
		rrb(stack_b, 0);
	}
	else
		return (0);
	return (3);
}
