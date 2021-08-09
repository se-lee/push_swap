#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;

	if (argc > 1)
	{
		init_stack(&stack_a);
		init_stack(&stack_b);
		store_to_stack(argv, &stack_a);
	// print_list(&stack_a);
		if (stack_a.node_count == 3)
			sort_three_args(&stack_a);
		else
			sort_five(&stack_a, &stack_b);
	}
	// printf("\nafter: \n");
	// print_list(&stack_a);

	return (0);
}

