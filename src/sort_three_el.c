/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_el.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 16:35:46 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_el(t_list	**stack_a, t_list	**stack_b)
{
	(void)stack_b;
	if ((*stack_a)->chislo < (*stack_a)->prev->chislo
		&& (*stack_a)->prev->chislo < (*stack_a)->prev->prev->chislo)
		return ;
	if ((*stack_a)->chislo < (*stack_a)->prev->prev->chislo)
	{
		sa(stack_a, 0);
		if ((*stack_a)->chislo > (*stack_a)->prev->chislo)
			ra(stack_a, 0);
	}
	else
	{
		ra(stack_a, 0);
		if ((*stack_a)->chislo > (*stack_a)->prev->chislo)
		{
			if ((*stack_a)->chislo > (*stack_a)->prev->prev->chislo)
				ra(stack_a, 0);
			else
				sa(stack_a, 0);
		}
	}
}
