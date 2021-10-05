#include "push_swap.h"

// static int init_next_el(t_list **stack_a);

int	main(int argc, char **argv)
{
	t_data	data;

	data.flag = 0;
	data.res = is_chislo(argc, argv);
	if (data.res != 1)
		return (0);
	data.massiv = create_massiv(argc, argv);
	data.stack_a = create_list(argc, argv, data.massiv);
	data.next = 1;
	data.argc = argc;
	data.stack_b = init_list("0");
	// sort_five_el(&data.stack_a, &data.stack_b);
	// data.next = init_next_el(&data.stack_a);
	// while (data.stack_a != NULL)
	// {
	// 	printf("%d %d\n", data.stack_a->chislo, data.stack_a->order);
	// 	data.stack_a = data.stack_a->prev;
	// }
	algoritm(&data.stack_a, &data.stack_b, &data);
	printf("%s\n", "stack_a =");
	while (data.stack_a != NULL)
	{
		printf("%d\n", (data.stack_a)->chislo);
		data.stack_a = (data.stack_a)->prev;
	}
	printf("%s\n", "stack_b =");
	while (data.stack_b != NULL)
	{
		printf("%d\n", (data.stack_b)->chislo);
		data.stack_b = (data.stack_b)->prev;
	}
	return (0);
}

// while (stack_a != NULL)
	// {
	// 	printf("%d\n", stack_a->chislo);
	// 	stack_a = stack_a->prev;
	// }

// static int init_next_el(t_list **stack_a)
// {
// 	t_list	*iterator;

// 	iterator = *stack_a;
// 	while (iterator != NULL)
// 	{
// 		if (iterator->order == 1)
// 			return (iterator->chislo);
// 		iterator = iterator->prev;
// 	}
// 	return (0);
// }

// while (data.stack_a != NULL)
	// {
	// 	printf("%d\n", (data.stack_a)->chislo);
	// 	data.stack_a = (data.stack_a)->prev;
	// }
	// printf("%s\n", "stack_b =");
	// while (data.stack_b != NULL)
	// {
	// 	printf("%d\n", (data.stack_b)->chislo);
	// 	data.stack_b = (data.stack_b)->prev;
	// }