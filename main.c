#include "push_swap.h"

int	after_main(int argc, char **argv)
{
	t_list	*stack;
	int	res;

	res = is_chislo(argc, argv);
	if (res != 1)
		return (0);
	stack = create_list(argc, argv);
	sa_or_sb(stack);
	return (0);
}

int	main(void)
{
	char **argv;
	argv[0] = "имя_программы";
	argv[1] = "12";
	argv[1] = "34";
	after_main(2, argv);
	return (0);
}
