/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_a_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 16:45:38 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	one_two_free_els_to_a(t_list **stack_a,
				t_list **stack_b, t_data *data);

int	put_in_a(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_pia	pia;

	data->flag++;
	pia.max = find_max_order(stack_b);
	pia.mid = (pia.max - data->next) / 2 + data->next;
	pia.qnty_push = 0;
	while (pia.qnty_push < pia.max - pia.mid + 1)
	{
		if (*stack_b == NULL)
			return (0);
		if (check_next_element(stack_a, stack_b, data) == 1)
			continue ;
		if (qnty_els_in_stack(stack_b) < 6)
			return (one_two_free_els_to_a(stack_a, stack_b, data));
		if ((*stack_b)->order >= pia.mid)
		{
			(*stack_b)->flag = data->flag;
			pa(stack_a, stack_b);
			top_down(stack_a, stack_b, data);
			pia.qnty_push++;
		}
		else
			rb(stack_b, 0);
	}
	return (qnty_els_in_stack(stack_b));
}

static int	one_two_free_els_to_a(t_list **stack_a,
				t_list **stack_b, t_data *data)
{
	t_list	*iterator;

	iterator = *stack_b;
	while (iterator)
	{
		iterator->flag = data->flag;
		iterator = iterator->prev;
	}
	check_next_element(stack_a, stack_b, data);
	while (qnty_els_in_stack(stack_b))
	{
		pa(stack_a, stack_b);
		top_down(stack_a, stack_b, data);
	}
	return (0);
}

int	qnty_els_in_stack(t_list **stack)
{
	int		qnty;
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
