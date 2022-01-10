/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/10 12:42:36 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	rra(t_list **stack)
{
	t_list	*buf;
	t_list	*bbuf;

	if ((*stack)->prev == NULL || (*stack) == NULL)
		return (0);
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	buf = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	bbuf = *stack;
	(*stack)->next = buf;
	(*stack) = (*stack)->next;
	(*stack)->next = NULL;
	(*stack)->prev = bbuf;
	return (0);
}

int	rrb(t_list **stack)
{
	t_list	*buf;
	t_list	*bbuf;

	if (((*stack)->prev == NULL) || ((*stack) == NULL))
		return (0);
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	buf = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	bbuf = *stack;
	(*stack)->next = buf;
	(*stack) = (*stack)->next;
	(*stack)->next = NULL;
	(*stack)->prev = bbuf;
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a) == NULL || (*stack_b) == NULL)
		return (0);
	rra(stack_a);
	rrb(stack_b);
	return (0);
}
