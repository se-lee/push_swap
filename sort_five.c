#include "push_swap.h"

/*
get mid number,
pb two numbers smaller than mid number,
in stack b, sort big->small
in stack a, do three number sort
pa two numbers
*/

void	sort_two(t_stack *stack)
{
	if (stack->top->content < stack->top->next->content)
		sb(stack);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	mid;
	int	pb_count;

	mid = get_mid_nbr_five(stack_a->top);
	pb_count = 0;
	while (stack_a)
	{
		if (stack_a->top->content < mid)
		{
			pb(stack_a, stack_b);
			pb_count++;
		}
		else
			ra(stack_a);
		if (pb_count == 2)
			break;	
	}
	sort_three_args(stack_a);
	sort_two(stack_b);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
