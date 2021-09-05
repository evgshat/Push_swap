#include "push_swap.h"

int	create_list(int argc, char *argv)
{
	int			i;
	t_struct	structura;

	i = 1;
	while (i <= argc)
	{
		structura.chislo[i] = argv[i] + '0';
		i++;
	}
	// printf("%d\n%d\n%d\n", structura.chislo[1], structura.chislo[2], structura.chislo[3]);
	return (1);
}
