/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:40:08 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/12 15:47:00 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_for_instr(t_data *data)
{
	ft_free_data(data);
	error("Error\n");
}

void	error(char *str)
{
	write(1, str, ft_strlen(str));
	exit (0);
}

void	ft_free_data(t_data *data)
{
	if (data->stack_a)
		free(data->stack_a);
	if (data->stack_b)
		free(data->stack_b);
}
