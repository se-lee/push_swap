#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack stack_a;

	if (argc > 1)
	{
		init_stack(&stack_a);
		store_to_stack(argv, &stack_a);
//		print_list(&stack_a);
		sort_three_args(&stack_a);
//		printf("\nafter: \n");
//		print_list(&stack_a);
	}
	return (0);
}
