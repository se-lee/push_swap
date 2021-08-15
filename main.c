#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc <= 1)
		return (0);
	if (arg_has_error(argv))
		print_error_exit();
	a = stack_init();
	stack_store_value(argv, a);
	// if (stack_is_sorted(a))
	// 	return (0);
	// print_list(a, 'a');
	// if (stack_has_duplicate(a))
	// 	print_error_exit();
	b = stack_init();
	push_swap(a, b);
// /* -------> erase below <-------*/	
	// print_list(a, 'a');
	// print_list(b, 'b');

// /* -------> erase erase <-------*/		

	return (0);
}
