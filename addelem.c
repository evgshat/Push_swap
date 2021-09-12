/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addelem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:30:51 by lcharlet          #+#    #+#             */
/*   Updated: 2021/09/12 18:29:22 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *addelem(t_list *stack, char *new_chislo)
{
	t_list *temp;
	t_list *p;
	int		chislo;

	chislo = ft_atoi(new_chislo);
	temp = (t_list*)malloc(sizeof(t_list)); //создаваемый
	p = (t_list *)stack->next;
	stack->next = (int *)temp;
	temp->chislo = chislo;
	stack->next = (int *)p;
	temp->prev = (int *)stack;
	if (p != NULL)
		p->prev = (int *)temp;
	return (temp);
}
