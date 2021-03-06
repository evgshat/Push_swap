/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_el.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 16:35:52 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	convert_stack(t_list **stack_a, t_stack_els *els);
static int	find_min(t_list **stack_a);
static void	sort_five_el_else(t_list **stack_a,
				t_list **stack_b, int min, int i);

void	sort_five_el(t_list	**stack_a, t_list **stack_b)
{
	t_stack_els	els;
	int			min;
	int			i;

	min = find_min(stack_a);
	i = 0;
	convert_stack(stack_a, &els);
	if (!(els.a < els.b && els.b < els.c && els.c < els.d && els.d < els.e))
	{
		if (els.b < els.a && els.a < els.c
			&& els.c < els.d && els.d < els.e)
			sa(stack_a, 0);
		else if (els.b < els.c && els.c < els.d
			&& els.d < els.e && els.e < els.a)
			ra(stack_a, 0);
		else if (els.e < els.a && els.a < els.b
			&& els.b < els.c && els.c < els.d)
			rra(stack_a, 0);
		else
			sort_five_el_else(stack_a, stack_b, min, i);
	}
}

static	void	sort_five_el_else(t_list **stack_a,
			t_list **stack_b, int min, int i)
{
	t_list		*iterator;

	iterator = *stack_a;
	while (iterator->chislo != min)
	{
		i++;
		iterator = iterator->prev;
	}
	if (i == 4)
		rra(stack_a, 0);
	if (i == 3 || i == 2)
	{
		if (i == 2)
			rra(stack_a, 0);
		rra(stack_a, 0);
		rra(stack_a, 0);
	}
	if (i == 1)
		sa(stack_a, 0);
	pb(stack_a, stack_b);
	sort_four_el(stack_a, stack_b);
	pa(stack_a, stack_b);
}

static void	convert_stack(t_list	**stack_a, t_stack_els	*els)
{
	els->a = (*stack_a)->chislo;
	els->b = (*stack_a)->prev->chislo;
	els->c = (*stack_a)->prev->prev->chislo;
	els->d = (*stack_a)->prev->prev->prev->chislo;
	els->e = (*stack_a)->prev->prev->prev->prev->chislo;
}

static int	find_min(t_list	**stack_a)
{
	int		min;
	t_list	*i;

	i = *stack_a;
	min = (*stack_a)->chislo;
	while (i != NULL)
	{
		if (i->chislo < min)
			min = i->chislo;
		i = i->prev;
	}
	return (min);
}
