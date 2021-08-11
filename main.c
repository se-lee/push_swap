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
//	push_small_to_b(&stack_a, &stack_b);
//	print_list(&stack_a, 'a');
	print_list(&stack_b, 'b');
	
	return (0);
}

	// 	if (stack_a.node_count == 3)
	// 		sort_three_args(&stack_a);
	// 	else
	// 		sort_five(&stack_a, &stack_b);
	// }
	// printf("\nafter: \n");
	// print_list(&stack_a, &stack_b);

