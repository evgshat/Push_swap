#include "push_swap.h"

int	create_list(int argc, char *argv)
{
	int			i;
	t_struct	structura;

	i = 0;
	while (i < argc)
	{
		structura.chislo[i] = ft_atoi(&argv[i]);
		i++;
	}
	// printf("%d\n%d\n%d\n", structura.chislo[1], structura.chislo[2], structura.chislo[3]);
	return (1);
}
