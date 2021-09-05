#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	printf("%s\n%s\n%s\n", argv[1], argv[2], argv[3]);
	while (i <= argc)
	{
		create_list(argc, argv[i]);
		i++;
	}
}