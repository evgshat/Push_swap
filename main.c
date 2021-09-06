#include "push_swap.h"

int	after_main(int argc, char **argv)
{
	int	i;

	i = 1;
	// printf("%s\n%s\n%s\n", argv[1], argv[2], argv[3]);
	if (argc == 1)
		printf ("%s", "Пусто");
	if (is_dig(argc, argv) == 0)
		printf ("%s", "Не число");
	else
		printf ("%s", "Число");
// захерачить все в один чекер
	while (i <= argc)
	{
		create_list(argc, argv[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	char **argv;

	argv[0] = "3363";
	argv[1] = "34";
	after_main(2, argv);
	return (0);
}