/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next_element_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:38:41 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 23:11:24 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		ra(stack_a);
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
			ra(stack_a);
		data->next++;
		return (1);
	}
	else if ((*stack_b) && (*stack_b)->prev
		&& (*stack_b)->prev->order == data->next)
		sb(stack_b);
	else if ((*stack_b) && find_last(stack_b)->order == data->next)
		rrb(stack_b);
	else if (*stack_b && find_last(stack_b)->next
		&& find_last(stack_b)->next->order == data->next)
	{
		rrb(stack_b);
		rrb(stack_b);
	}
	else
		return (0);
	return (3);
}
