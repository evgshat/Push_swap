/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:30:51 by lcharlet          #+#    #+#             */
/*   Updated: 2021/09/12 17:58:50 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *init_list(char *str)
{
	t_list *stack;
	int		chislo;

	chislo = ft_atoi(str);
	stack = (t_list*)malloc(sizeof(t_list));
	stack->chislo = chislo;
	stack->prev = NULL;
	stack->next = NULL;
	return (stack);
}