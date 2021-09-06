#include "push_swap.h"

int	is_dig(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		if (argv[i][j] == '0')
		{
			j++;
			if (argv[i][j] != '\0')
				return (0);
		}
		if (argv[i][j] == '-')
		{
			j++;
			{
				if (argv[i][j] == '0')
					return (0);
			}
		}
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < 48 || argv[i][j] > 71)
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

// int	one_string_is_dig () разделить на две функции
// {

// }
