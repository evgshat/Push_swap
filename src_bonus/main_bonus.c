/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:13:54 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/09 17:45:45 by lcharlet         ###   ########.fr       */
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

static void	check_instr(t_data *data, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(&data->stack_a, 0);
	printf("%d\n", data->stack_a->chislo);
}

void	checker(t_data *data)
{
	char *line;

	line = get_next_line(0);
	while (line)
	{
		check_instr(data, line);
		line = get_next_line(0);
	}
}

int main(int argc, char **argv)
{
	t_data	data;

	if ((data.res = is_norm_args(argc, argv) < 0))
		error("Error\n");
	data.massiv = create_massiv(argc, argv);
	data.stack_a = create_list(argc, argv, data.massiv);
	data.stack_b = NULL;
	checker(&data);
}