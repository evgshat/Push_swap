/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_chislo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:30:51 by lcharlet          #+#    #+#             */
/*   Updated: 2021/09/12 19:57:32 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_chislo(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (argc == 1)
	{
		printf ("%s", "Пусто\n");
		return (0);
	}
	while (i < argc)
	{
		if (argv[i][j] == '0')
		{
			j++;
			if (argv[i][j] != '\0')
			{
				printf ("%s", "Не число\n");
				return (0);
			}
		}
		if (argv[i][j] == '-')
		{
			j++;
			{
				if (argv[i][j] == '0')
					return (0);
			}
		}
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < 48 || argv[i][j] > 71)
			{
				printf ("%s", "Не число\n");
				return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	printf ("%s", "Число\n");
	return (1);
}
