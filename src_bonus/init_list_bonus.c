/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:30:51 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 17:24:15 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*init_list(char *str)
{
	t_list		*stack;
	long		number;

	number = ft_atoi(str);
	stack = malloc(sizeof(t_list));
	if (!stack)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	stack->chislo = number;
	stack->prev = 0;
	stack->next = 0;
	stack->flag = 0;
	return (stack);
}
