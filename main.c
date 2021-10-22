/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/21 21:54:00 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.flag = 0;
	data.res = is_norm_args(argc, argv);
	if (data.res < 0)
	{
		write (1, "Wrong_args\n", 11);
		return (0);
	}
	else if (data.res == 2)
		return (0);
	data.massiv = create_massiv(argc, argv);
	data.stack_a = create_list(argc, argv, data.massiv);
	data.next = 1;
	data.argc = argc;
	data.stack_b = NULL;
	algoritm(&data.stack_a, &data.stack_b, &data);
	return (0);
}
