/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addelem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:30:51 by lcharlet          #+#    #+#             */
/*   Updated: 2021/09/24 22:07:44 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*addelem(t_list **stack, char *new_chislo)
{
	t_list	*temp;
	t_list	*p;
	int		number;

	number = ft_atoi(new_chislo);
	temp = malloc(sizeof(t_list)); //создаваемый
	p = (*stack)->next;
	(*stack)->next = temp;
	temp->chislo = number;
	temp->next = p;
	temp->prev = *stack;
	if (p != NULL)
		p->prev = temp;
	printf("%d\n", (*stack)->chislo);
	return (temp);
}
