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
// check if sorted - where do i free?
	if (stack_is_sorted(&a))
		return (0);
	if (a.node_count < 5)
		sort_less_five(&a, &b, a.node_count, A);
	else if (a.node_count == 5)
		sort_five(&a, &b);
	else 
		sort_a(&a, &b, a.node_count);
// put all above in a function push_swap
	print_list(&a, 'a');
	print_list(&b, 'b');
	
	return (0);
}
