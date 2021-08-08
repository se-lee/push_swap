#include "push_swap.h"

/*
pb top two numbers,
in stack b, sort big->small
in stack a, do three number sort
pa two numbers
*/

void	sort_two(t_stack *stack)
{
	// if (stack->top->content > stack->top->next->content)
	// 	return ;
	// else 
	if (stack->top->content < stack->top->next->content)
		sb(stack);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);

print_list(stack_b);
printf("b_top:%d  ", stack_b->top->content);
	// if (stack_b->top->content < stack_b->top->next->content)
	// 	sb(stack_b);
	sort_three_args(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init_stack(&a);
	init_stack(&b);
	store_to_stack(argv, &a);
	sort_five(&a, &b);

	print_list(&a);
	
	return (0);
}

