/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_norm_args_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:30:51 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 17:22:21 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	already_sort(int argc, char **argv);
static int	check_on_wrong_args(int *argc, char **argv, int *i, int *j);
static void	next(int *i, int *j);
static int	check_int(int argc, char **argv);

int	is_norm_args(int argc, char **argv)
{
	int	i;
	int	j;
	int	res;

	i = 1;
	j = 0;
	res = 1;
	res = check_on_wrong_args(&argc, argv, &i, &j);
	if (res != 0)
		return (-1);
	res = check_int(argc, argv);
	if (res < 0)
		return (-1);
	res = check_double(argc, argv);
	if (res < 0)
		return (-1);
	res = already_sort(argc, argv);
	if (res == 0)
		return (2);
	return (0);
}

static int	check_on_wrong_args(int *argc, char **argv, int *i, int *j)
{
	while (*i < *argc)
	{
		if (argv[*i][*j] == '0')
		{
			*j = *(j) + 1;
			if (argv[*i][*j] != '\0')
				return (-1);
		}
		if (argv[*i][*j] == '-')
		{
			*j = *(j) + 1;
			{
				if (argv[*i][*j] == '0')
					return (-1);
			}
		}
		while (argv[*i][*j] != '\0')
		{
			if (argv[*i][*j] < 48 || argv[*i][*j] > 71)
				return (-1);
			*j = *(j) + 1;
		}
		next(i, j);
	}
	return (0);
}

static void	next(int *i, int *j)
{
	*i = *(i) + 1;
	*j = 0;
}

static int	already_sort(int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i > 1)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i - 1]))
			i--;
		else
			return (-1);
	}
	return (0);
}

static int	check_int(int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i >= 1)
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (-1);
		i--;
	}
	return (0);
}
