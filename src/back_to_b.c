/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:38:41 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 16:36:27 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	back_to_b_two(t_list **stack_a, t_list **stack_b, t_data *data);

void	back_to_b(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	flag;

	flag = (*stack_a)->flag;
	while ((*stack_a)->flag == flag && flag != 0 && !is_sorted(stack_a))
	{
		while ((*stack_a)->order == data->next)
		{
			if (*stack_b && (*stack_b)->order < data->next)
				rr(stack_a, stack_b);
			else
				ra(stack_a, 0);
			data->next++;
		}
		back_to_b_two(stack_a, stack_b, data);
		if ((*stack_a)->flag == flag)
			pb(stack_a, stack_b);
	}
}

static void	back_to_b_two(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while (*stack_b && ((*stack_b)->order == data->next))
	{
		if ((*stack_b)->order == data->next)
		{
			pa(stack_a, stack_b);
			if (*stack_b && (*stack_b)->order < data->next)
				rr(stack_a, stack_b);
			else
				ra(stack_a, 0);
			data->next++;
		}
	}
}
