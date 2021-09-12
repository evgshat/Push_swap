/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addelem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:30:51 by lcharlet          #+#    #+#             */
/*   Updated: 2021/09/12 19:32:10 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *addelem(t_list *stack, char *new_chislo)
{
	t_list *temp;
	t_list *p;
	int		chislo;

	if (stack->next != NULL)
	{
		while (stack->next != NULL)
			stack = (t_list *)stack->next;
	}
	chislo = ft_atoi(new_chislo);
	temp = (t_list*)malloc(sizeof(t_list)); //создаваемый
	p = (t_list *)stack->next;
	stack->next = temp;
	temp->chislo = chislo;
	temp->next = p;
	temp->prev = stack;
	if (p != NULL)
		p->prev = temp;
	return (temp);
}
