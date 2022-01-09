/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 22:02:20 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_list **stack)
{
	t_list	*buf;
	t_list	*bbuf;

	if (*stack == NULL || (*stack)->prev == NULL)
		return ;
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
}

void	rrb(t_list **stack)
{
	t_list	*buf;
	t_list	*bbuf;

	if (*stack == NULL || (*stack)->prev == NULL)
		return ;
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
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
