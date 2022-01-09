/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:38:41 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 16:36:26 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_number(int argc, char **argv, int num, int i);

int	check_double(int argc, char **argv)
{
	int	i;
	int	num;
	int	res;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		res = check_number(argc, argv, num, i);
		if (res < 0)
			return (-1);
		i++;
	}
	return (0);
}

static int	check_number(int argc, char **argv, int num, int i)
{
	int	all_num;

	i = i + 1;
	while (i < argc)
	{
		all_num = ft_atoi(argv[i]);
		if (all_num == num)
			return (-1);
		i++;
	}
	return (0);
}
