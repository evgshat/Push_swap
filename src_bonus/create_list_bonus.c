/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/10 12:27:59 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*create_list(int argc, char **argv)
{
	int			i;
	t_list		*stack;

	i = argc - 1;
	stack = init_list(argv[i]);
	i--;
	while (i > 0)
	{
		stack = addelem(&stack, argv[i]);
		i--;
	}
	return (stack);
}
