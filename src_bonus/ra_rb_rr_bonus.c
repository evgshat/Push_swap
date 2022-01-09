/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 22:03:29 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_list **stack)
{
	t_list	*buf;
	t_list	*iterator;

	if (*stack == NULL || (*stack)->prev == NULL)
		return ;
	buf = (*stack);
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	iterator = *stack;
	while (iterator->prev != NULL)
		iterator = iterator->prev;
	iterator->prev = buf;
	buf->prev = NULL;
	buf->next = iterator;
}

void	rb(t_list **stack)
{
	t_list	*buf;
	t_list	*iterator;

	if (*stack == NULL || (*stack)->prev == NULL)
		return ;
	buf = (*stack);
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	iterator = *stack;
	while (iterator->prev != NULL)
		iterator = iterator->prev;
	iterator->prev = buf;
	buf->prev = NULL;
	buf->next = iterator;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
