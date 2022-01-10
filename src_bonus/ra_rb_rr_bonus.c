/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/10 12:41:47 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ra(t_list **stack)
{
	t_list	*buf;
	t_list	*iterator;

	if (*stack == NULL || (*stack)->prev == NULL)
		return (0);
	buf = (*stack);
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	iterator = *stack;
	while (iterator->prev != NULL)
		iterator = iterator->prev;
	iterator->prev = buf;
	buf->prev = NULL;
	buf->next = iterator;
	return (0);
}

int	rb(t_list **stack)
{
	t_list	*buf;
	t_list	*iterator;

	if (*stack == NULL || (*stack)->prev == NULL)
		return (0);
	buf = (*stack);
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	iterator = *stack;
	while (iterator->prev != NULL)
		iterator = iterator->prev;
	iterator->prev = buf;
	buf->prev = NULL;
	buf->next = iterator;
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a) == NULL || (*stack_b) == NULL)
		return (0);
	ra(stack_a);
	rb(stack_b);
	return (0);
}
