#include "push_swap.h"

int		get_pivot(t_stack *stack)
{
	int	pivot;
	int	min;
	int	max;

	min = get_min_nbr(stack);
	max = get_max_nbr(stack);
	pivot = (min + max) / 2;

	return (pivot);
}

void	a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;
	t_node	*cursor;

	pivot = get_pivot(stack_a);
printf("[ab]pivot: %d\n", pivot);
	cursor = stack_a->top;
	while (cursor->next != NULL)
	{
		if (cursor->content <= pivot)
		{
		cursor = cursor->next;	
			pb(stack_a, stack_b);
		}
		else if (cursor->content > pivot)
		{
		cursor = cursor->next;
			ra(stack_a);
		}
	}
}

