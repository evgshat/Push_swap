/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 16:45:29 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_list **stack, int is_rrr)
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
	if (!is_rrr)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack, int is_rrr)
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
	if (!is_rrr)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	write(1, "rrr\n", 4);
}
