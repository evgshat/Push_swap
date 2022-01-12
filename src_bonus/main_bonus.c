/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:13:54 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/12 15:47:28 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_strncmp(char *line, char *str)
{
	int	i;

	i = 0;
	while (line[i] || str[i])
	{
		if (line[i] != str[i])
			return (1);
		i++;
	}
	return (0);
}

static void	check_instr(t_data *data, char *line)
{
	if (!ft_strncmp(line, "sa\n"))
		sa(&data->stack_a);
	else if (!ft_strncmp(line, "sb\n"))
		sb(&data->stack_b);
	else if (!ft_strncmp(line, "ss\n"))
		ss(&data->stack_a, &data->stack_b);
	else if (!ft_strncmp(line, "pa\n"))
		pa(&data->stack_a, &data->stack_b);
	else if (!ft_strncmp(line, "pb\n"))
		pb(&data->stack_a, &data->stack_b);
	else if (!ft_strncmp(line, "ra\n"))
		ra(&data->stack_a);
	else if (!ft_strncmp(line, "rb\n"))
		rb(&data->stack_b);
	else if (!ft_strncmp(line, "rr\n"))
		rr(&data->stack_a, &data->stack_b);
	else if (!ft_strncmp(line, "rra\n"))
		rra(&data->stack_a);
	else if (!ft_strncmp(line, "rrb\n"))
		rrb(&data->stack_b);
	else if (!ft_strncmp(line, "rrr\n"))
		rrr(&data->stack_a, &data->stack_b);
	else
		error_for_instr(data);
}

static int	result(t_data *data)
{
	while (data->stack_a->prev)
	{
		if (data->stack_a->chislo > data->stack_a->prev->chislo)
		{
			write (1, "KO\n", 3);
			return (0);
		}
		data->stack_a = data->stack_a->prev;
	}
	write (1, "OK\n", 3);
	return (0);
}

void	checker(t_data *data)
{
	char	*line;

	line = get_next_line(0);
	if (!line)
		exit (0);
	while (line)
	{
		check_instr(data, line);
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc >= 2)
	{
		data.res = is_norm_args(argc, argv);
		if (data.res < 0)
			error("Error\n");
		data.stack_a = create_list(argc, argv);
		data.stack_b = NULL;
		checker(&data);
		result(&data);
		ft_free_data(&data);
	}
}
