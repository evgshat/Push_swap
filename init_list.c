/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:30:51 by lcharlet          #+#    #+#             */
/*   Updated: 2021/09/24 19:46:34 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_list(char *str)
{
	t_list	*stack;
	int		number;

	number = ft_atoi(str);
	stack = malloc(sizeof(t_list));
	if (!stack)
		printf("%s\n", "not memory for point");
	stack->chislo = number;
	stack->prev = 0;
	stack->next = 0;
	printf("%d\n", stack->chislo);
	printf("%s\n", "end of init_list");
	return (stack);
}