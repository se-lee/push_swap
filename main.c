#include "push_swap.h"

/*
check the number of elements (number of arguments? number of nodes?)
if
*/

int	main(int argc, char **argv)
{
	t_stack stack_a;
//	t_stack stack_b;

	if (argc > 1)
	{
		init_stack(&stack_a);
		store_to_stack(argv, &stack_a);
		print_list(&stack_a);
	printf("[main]size: %d  ", stack_a.node_count);
		if (stack_a.node_count == 3)
			sort_three_args(&stack_a);
		// else if (stack_a.node_count > 3)
		// {
		// 	a_to_b(&stack_a, &stack_b);
		// }
	}
	printf("\nafter: \n");
	print_list(&stack_a);

	return (0);
}

