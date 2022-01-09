/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 16:45:33 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_list **stack, int is_rr)
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
	if (!is_rr)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack, int is_rr)
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
	if (!is_rr)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	write(1, "rr\n", 3);
}
