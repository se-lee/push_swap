#include "push_swap.h"



void	a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;
	t_node	*cursor;

//	pivot = stack_a->top->content;
	pivot = get_avg_nbr(stack_a);
printf("[ab]pivot: %d\n", pivot);
	cursor = stack_a->top;
	while (cursor->next != NULL)
	{
		if (cursor->content <= pivot)
			pb(stack_a, stack_b);
		else if (cursor->content > pivot)
			ra(stack_a);
		cursor = cursor->next;
	}
}

