#include "push_swap.h"

void top_down(t_list **stack_a, t_data *data)
{
	while ((*stack_a)->order == data->next || (*stack_a)->prev->order == data->next)
	{
		if  ((*stack_a)->prev->order == data->next)
			sa(stack_a, 0);
		ra(stack_a, 0);
		data->next++;
	}
}
