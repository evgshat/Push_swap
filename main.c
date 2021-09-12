#include "push_swap.h"

int	after_main(int argc, char **argv)
{
	int	i;
	t_list	*stack;

	i = 1;
	is_chislo(argc, argv);
	stack = create_list(argc, argv);
	return (0);
}

int	main(void)
{
	char **argv;
	argv[0] = "12";
	argv[1] = "34";
	after_main(2, argv);
	return (0);
}