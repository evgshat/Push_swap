/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 22:26:00 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// static void	paste_order(t_list **stack, int	*massiv, int argc);

// t_list	*create_list(int argc, char **argv, int *massiv)
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
		// printf("%d", stack->chislo);
		i--;
	}
	// paste_order(&stack, massiv, argc);
	return (stack);
}

// static void	paste_order(t_list **stack, int	*massiv, int argc)
// {
// 	int		i;
// 	int		m;
// 	t_list	*p;

// 	i = argc - 1;
// 	m = 0;
// 	while (i > 0)
// 	{
// 		p = *stack;
// 		while (p->chislo != massiv[m])
// 			p = p->prev;
// 		if (p->chislo == massiv[m])
// 		{
// 			p->order = i;
// 			i--;
// 			m++;
// 		}
// 	}
// 	free (massiv);
// }
