#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;

	if (argc <= 1)
		return (0);
	check_non_int(argv);
// check max/min int
	init_stack(&a, &b);
	store_to_stack(argv, &a);
	check_duplicate(a.top);
// check if sorted - do i free here before return 0?
	if (stack_is_sorted(&a))
		return (0);
	push_swap(&a, &b);

// /* -------> erase below <-------*/	
	print_list(&a, 'a');
	print_list(&b, 'b');
// /* -------> erase erase <-------*/		


	return (0);
}
