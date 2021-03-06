/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_massiv_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 17:29:43 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	*sort_massiv(int *massiv, int argc);
static void	obmen(int *m_first, int *m_second, int *massiv);
static void	sort_massiv_two(int *massiv, int *argc, int *flag);

int	*create_massiv(int argc, char **argv)
{
	int	i;
	int	m;
	int	number;
	int	*massiv;

	i = 1;
	m = 0;
	massiv = malloc(sizeof(int) * (argc - 1));
	while (i < argc)
	{
		number = ft_atoi(argv[i]);
		massiv[m] = number;
		m++;
		i++;
	}
	massiv = sort_massiv(massiv, argc);
	return (massiv);
}

static int	*sort_massiv(int *massiv, int argc)
{
	int	flag;

	if (argc < 3)
		return (massiv);
	flag = 1;
	sort_massiv_two(massiv, &argc, &flag);
	return (massiv);
}

static void	sort_massiv_two(int *massiv, int *argc, int *flag)
{
	int	m_first;
	int	m_second;

	while (*flag == 1)
	{
		*flag = 0;
		m_first = 0;
		m_second = 1;
		while (m_second < (*argc - 1))
		{
			if (massiv[m_first] < massiv[m_second])
			{
				obmen(&m_first, &m_second, massiv);
				*flag = 1;
			}
			else
			{
				m_first++;
				m_second++;
			}
		}
	}
}

static void	obmen(int *m_first, int *m_second, int *massiv)
{
	int	temp;

	temp = massiv[*m_first];
	massiv[*m_first] = massiv[*m_second];
	massiv[*m_second] = temp;
}
