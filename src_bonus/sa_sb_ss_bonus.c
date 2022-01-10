/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/10 18:22:33 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	sa(t_list **stack)
{
	t_list	*ch_top;
	t_list	*ch_top_minus_minus;

	if ((*stack) == NULL || (*stack)->prev == NULL)
		return (0);
	ch_top = *stack;
	if ((*stack)->prev->prev != NULL)
		ch_top_minus_minus = (*stack)->prev->prev;
	else
		ch_top_minus_minus = NULL;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	(*stack)->prev = ch_top;
	if (ch_top_minus_minus != NULL)
		ch_top_minus_minus->next = ch_top;
	ch_top->next = *stack;
	ch_top->prev = ch_top_minus_minus;
	return (0);
}

int	sb(t_list **stack)
{
	t_list	*ch_top;
	t_list	*ch_top_minus_minus;

	if ((*stack) == NULL || (*stack)->prev == NULL)
		return (0);
	ch_top = *stack;
	if ((*stack)->prev->prev != NULL)
		ch_top_minus_minus = (*stack)->prev->prev;
	else
		ch_top_minus_minus = NULL;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	(*stack)->prev = ch_top;
	if (ch_top_minus_minus != NULL)
		ch_top_minus_minus->next = ch_top;
	ch_top->next = *stack;
	ch_top->prev = ch_top_minus_minus;
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->prev == NULL || (*stack_a) == NULL
		|| (*stack_b)->prev == NULL || (*stack_b) == NULL)
		return (0);
	sa(stack_a);
	sb(stack_b);
	return (0);
}
