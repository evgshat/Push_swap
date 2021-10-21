/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/16 20:04:38 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void back_b_flags(t_list **stack_a, t_list **stack_b, t_data *data, int max_order);
static void loop_put_in_a(t_list **stack_a, t_list **stack_b, t_data *data, int max_for_b);

void	algoritm(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	max_for_b;

	if (data->argc < 7)
	{
		less_six(stack_a, stack_b, data);
		return ;
	}
	data->max_order = find_max_order(stack_a);
	data->mid_order = data->max_order/2 + data->next;
	max_for_b = data->mid_order;
	put_in_b(stack_a, stack_b, data);
	loop_put_in_a(stack_a, stack_b, data, max_for_b);
	back_b_flags(stack_a, stack_b, data, max_for_b);
	sort_second_half(stack_a, stack_b, data, data->max_order, data->mid_order);
}

static void loop_put_in_a(t_list **stack_a, t_list **stack_b, t_data *data, int max_for_b)
{
	while (max_for_b > 0)
	{
		max_for_b = put_in_a(stack_a, stack_b, data, max_for_b);
		top_down(stack_a, data);
	}
}

static void back_b_flags(t_list **stack_a, t_list **stack_b, t_data *data, int max_for_b)
{
	while ((*stack_a)->flag != 0)
	{
		max_for_b = back_to_b(stack_a, stack_b, data);
		while (max_for_b > 0)
		{
			max_for_b = put_in_a(stack_a, stack_b, data, max_for_b);
			top_down(stack_a, data);
		}
	}
}

int	find_max_order(t_list **stack)
{
	int		max_order;
	t_list	*p;

	p = *stack;
	max_order = 0;
	if (*stack == NULL)
		return (0);
	while (p->prev != NULL)
	{
		max_order++;
		p = p->prev;
	}
	max_order++;
	return (max_order);
}

void less_six (t_list **stack_a, t_list **stack_b, t_data *data)
{
	void (*funcs[4])(t_list **stack_a, t_list **stack_b);
	funcs[0] = &sort_two_el;
	funcs[1] = &sort_three_el;
	funcs[2] = &sort_four_el;
	funcs[3] = &sort_five_el;

	funcs[data->argc - 3](stack_a, stack_b);
}
