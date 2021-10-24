/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/24 16:38:01 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"



int gnl(t_list **stack_a, t_list **stack_b)
{
	char *str;

	str = malloc(sizeof(char *));
	if (str == 0)
	{
		write (1, "Error", 6);
		return (-1);
	}
	str = get_next_line(0);
	while (str)
	{
		if (str[0] == 's' && str[1] == 'a' && str[2] == '\0')
			sa(stack_a, 0);
		if (str[0] == 's' && str[1] == 'b' && str[2] == '\0')
			sb(stack_b, 0);
		if (str[0] == 's' && str[1] == 's' && str[2] == '\0')
			ss_bonus(stack_a, stack_b);
		if (str[0] == 'r' && str[1] == 'a' && str[2] == '\0')
			ra(stack_a, 0);
		if (str[0] == 'r' && str[1] == 'b' && str[2] == '\0')
			rb(stack_b, 0);
		if (str[0] == 'r' && str[1] == 'r' && str[2] == '\0')
			rr_bonus(stack_a, stack_b);
		if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a' && str[3] == '\0')
			rra(stack_a, 0);
		if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b' && str[3] == '\0')
			rrb(stack_b, 0);
		if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r' && str[3] == '\0')
			rrr_bonus(stack_a, 0);
		if (str[0] == 'p' && str[1] == 'a' && str[2] == '\0')
			pa_bonus(stack_a, stack_b);
		if (str[0] == 'p' && str[1] == 'b' && str[2] == '\0')
			pb_bonus(stack_a, stack_b);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_data data;

	data.res = is_norm_args(argc, argv);
	if (data.res < 0)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	else if (data.res == 2)
		return (0);
	data.massiv = create_massiv(argc, argv);
	data.stack_a = create_list(argc, argv, data.massiv);
	data.stack_b = NULL;
	gnl(&data.stack_a, &data.stack_b);
}