#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;

	if (argc <= 1)
		return (0);
	init_stack(&a, &b);
	store_to_stack(argv, &a);

	if (a.node_count < 5)
		sort_less_five(&a, &b, a.node_count, A);
	else if (a.node_count == 5)
		sort_five(&a, &b);
	else 
		sort_a(&a, &b, a.node_count);

	// b_sort_three(&b);

	// sort_b(&stack_a, &stack_b, stack_b.node_count);
	print_list(&a, 'a');
	print_list(&b, 'b');
	
	return (0);
}
