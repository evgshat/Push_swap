/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:38:41 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/13 20:06:36 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	back_to_b(t_list **stack_a, t_list **stack_b)
{
	int flag;
	int max_order;

	flag = (*stack_a)->flag;
	max_order = (*stack_a)->order;
	while ((*stack_a)->flag == flag && flag != 0)
	{
		if (max_order < (*stack_a)->order)
			max_order = (*stack_a)->order;
		pb(stack_a, stack_b);
	}
	return (max_order);
}
