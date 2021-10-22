// #include "get_next_line.h"
#include "push_swap.h"
#include "stdarg.h"

// int	sort(char *str)
// {
// 	while (get_next_line(0))
// 	{
// 		if ()
// 	}
// }

int main	(int argc, char **argv)
{
	t_check	check;
	(void) argc;
	char ch;

	// check.res = is_norm_args(argc, argv);
	// if (check.res < 0)
	// {
	// 	write (1, "Error\n", 6);
	// 	return (0);
	// }
	// else if (check.res == 2)
	// {
	// 	write (1, "OK\n", 3);
	// 	return (0);
	// }
	// check.massiv = create_massiv(argc, argv);
	// check.stack_a = create_list(argc, argv, check.massiv);
	check.str = malloc(sizeof(char *));
	check.j = 0;
	check.j_str = 0;
	check.i = 0;
	check.str[check.j_str] = argv[1][4];
	read(0, &ch, 1);
	printf("%c", ch);
	printf("%c", check.str[check.j_str]);
	// printf("%c", argv[check.j_str][check.i]);

	// while (argc != 1)
	// {
	// 	check.j = 1;
	// 	check.j_str = 0;
	// 	while (argv[check.j])
	// 	{
	// 		check.i = 0;
	// 		check.str = malloc(sizeof(char *));
	// 		while (argv[check.j][check.i] != '\0')
	// 		{
	// 			check.str[check.j][check.i] = argv[check.j][check.i];
	// 			check.i++;
	// 		}
	// 		check.j++;
	// 		check.j_str = 0;
	// 	}
	// }
	// check.j_str = 0;
	// while (check.str[check.j_str])
	// {
	// 	printf("%s", check.str[check.j_str]);
	// 	check.j_str++;
	// }
}
