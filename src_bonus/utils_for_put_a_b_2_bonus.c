/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_put_a_b_2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 23:11:55 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*find_last(t_list **stack_b)
{
	t_list	*last;

	last = *stack_b;
	if (!last)
		return (NULL);
	while (last->prev != NULL)
		last = last->prev;
	return (last);
}

long	ft_atoi(const char *string)
{
	int				i;
	int				sign;
	long int		res;

	i = 0;
	res = 0;
	sign = 0;
	if ((string[i] < '0' || string[i] > '9')
		&& (string[i] < '\t' || string[i] > '\r')
		&& (string[i] != ' ') && (string[i] != '-') && (string[i] != '+'))
		return (0);
	while ((string[i] >= '\t' && string[i] <= '\r') || (string[i] == ' ')
		|| (string[i] == '0'))
		i++;
	if (string[i] == '+' || string[i] == '-')
	{
		if (string[i] == '-')
			sign = -1;
		i++;
	}
	while (string[i] >= '0' && string[i] <= '9')
		res = res * 10 + (string[i++] - '0');
	if (sign == -1)
		return (res * sign);
	return (res);
}
