/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_put_a_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 16:35:39 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				sa(stack_a, 0);
		}
		if ((*stack_b) && (*stack_b)->order < data->next)
			rr(stack_a, stack_b);
		else
			ra(stack_a, 0);
		data->next++;
	}
}
