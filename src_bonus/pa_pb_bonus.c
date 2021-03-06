/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/10 18:14:35 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	pa_two(t_list **stack_a, t_list	*buf);
static void	pb_two(t_list **stack_b, t_list	*buf);

int	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*buf;

	if ((*stack_b) == NULL)
		return (0);
	buf = *stack_b;
	*stack_b = (*stack_b)->prev;
	if (*stack_b != NULL)
		(*stack_b)->next = NULL;
	if (!(*stack_a))
	{
		*stack_a = malloc(sizeof(t_list));
		(*stack_a)->chislo = buf->chislo;
		(*stack_a)->flag = buf->flag;
		(*stack_a)->order = buf->order;
		(*stack_a)->next = NULL;
		(*stack_a)->prev = NULL;
	}
	else
		pa_two(stack_a, buf);
	free (buf);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*buf;

	if ((*stack_a) == NULL)
		return (0);
	buf = *stack_a;
	*stack_a = (*stack_a)->prev;
	if (*stack_a)
		(*stack_a)->next = NULL;
	if (!(*stack_b))
	{
		*stack_b = malloc(sizeof(t_list));
		(*stack_b)->chislo = buf->chislo;
		(*stack_b)->flag = buf->flag;
		(*stack_b)->order = buf->order;
		(*stack_b)->next = NULL;
		(*stack_b)->prev = NULL;
	}
	else
		pb_two(stack_b, buf);
	free (buf);
	return (0);
}

static void	pa_two(t_list **stack_a, t_list	*buf)
{
	(*stack_a)->next = malloc(sizeof(t_list));
	(*stack_a)->next->chislo = buf->chislo;
	(*stack_a)->next->flag = buf->flag;
	(*stack_a)->next->order = buf->order;
	(*stack_a)->next->next = NULL;
	(*stack_a)->next->prev = *stack_a;
	*stack_a = (*stack_a)->next;
}

static void	pb_two(t_list **stack_b, t_list	*buf)
{
	(*stack_b)->next = malloc(sizeof(t_list));
	(*stack_b)->next->chislo = buf->chislo;
	(*stack_b)->next->flag = buf->flag;
	(*stack_b)->next->order = buf->order;
	(*stack_b)->next->next = NULL;
	(*stack_b)->next->prev = *stack_b;
	*stack_b = (*stack_b)->next;
}
