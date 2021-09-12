/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delelem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:30:51 by lcharlet          #+#    #+#             */
/*   Updated: 2021/09/12 18:28:31 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *delelem(t_list *stack)
{
	t_list *prev;
	t_list *next;

	prev = (t_list *)stack->prev;
	next = (t_list *)stack->next;
	if (prev != NULL)
		prev->next = stack->next;
	if (next != NULL)
		next->prev = stack->prev;
	free (stack);
	return (prev);
}