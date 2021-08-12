#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;

	if (argc <= 1)
		return (0);

	init_stack(&stack_a, &stack_b);
	store_to_stack(argv, &stack_a);

	print_list(&stack_a, 'a');
	a_to_b_sort(&stack_a, &stack_b, stack_a.node_count);
	b_to_a_sort(&stack_a, &stack_b, stack_b.node_count);
	print_list(&stack_a, 'a');
	print_list(&stack_b, 'b');
	
	return (0);
}
