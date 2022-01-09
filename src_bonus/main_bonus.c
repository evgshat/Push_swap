/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:13:54 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 23:17:16 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// должен читать инструкции из стандартного ввода, после которой /n
// вроде чекер должен выполнить все инструкции на аргументах
// если все ок - чекер пишет "OK\n", иначе "KO\n"
// если ошибка в аргуменах - "Error\n" - не integer, больше, чем integer, есть дубли, не существует такой инструкции или некорректный формат (инструкции?)

#include "push_swap_bonus.h"

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

void error(char *str)
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

static void	check_instr(t_data *data, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(&data->stack_a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb(&data->stack_b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(&data->stack_a, &data->stack_b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		pa(&data->stack_a, &data->stack_b);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
	{
		printf("111");
		pb(&data->stack_a, &data->stack_b);
	}
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra(&data->stack_a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rb(&data->stack_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(&data->stack_a, &data->stack_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && line[3] == '\n')
		rra(&data->stack_a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b' && line[3] == '\n')
		rra(&data->stack_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r' && line[3] == '\n')
		rrr(&data->stack_a, &data->stack_b);
	else
	{
		ft_free_data(data);
		error("Error\n");
	}
}

int	result(t_data *data)
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
	char *line;
	printf("222");

	line = get_next_line(0);
	while (line)
	{
		printf("222");
		printf("%s", line);
		check_instr(data, line);
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
}

int main(int argc, char **argv)
{
	printf("2222");
	t_data	data;

	if (argc >= 2)
	{
		printf("2222");
		if ((data.res = is_norm_args(argc, argv) < 0))
			error("Error\n");
		data.stack_a = create_list(argc, argv);
		data.stack_b = NULL;
		checker(&data);
		result(&data);
		ft_free_data(&data);
	}
}