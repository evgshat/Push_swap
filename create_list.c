#include "push_swap.h"

static void	paste_order(t_list **stack, int	*massiv, int argc);

t_list	*create_list(int argc, char **argv, int *massiv)
{
	int			i;
	t_list		*stack;

	i = 1;
	stack = init_list(argv[i]);
	i++;
	while (i < argc)
	{
		stack = addelem(&stack, argv[i]);
		i++;
	}
	paste_order(&stack, massiv, argc);
	return (stack);
}

static void	paste_order(t_list **stack, int	*massiv, int argc)
{
	int		i;
	int		m;
	t_list	*p;

	i = 1;
	m = 0;
	while (i < argc)
	{
		p = *stack;
		while (p->chislo != massiv[m])
			p = p->prev;
		if (p->chislo == massiv[m])
		{
			p->order = i;
			i++;
			m++;
		}
	}
}
