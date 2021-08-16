#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;

	if (argc <= 1)
		return (0);
	if (arg_has_error(argv))
		print_error_exit();
	stack_init(&push_swap.a);
	stack_init(&push_swap.b);
	stack_store_value(argv, &push_swap.a);
	if (stack_has_duplicate(&push_swap.a))
		print_error_exit();
	push_swap_solve(&push_swap);
	program_run(&push_swap.program);
	stack_free_all(&push_swap.a, &push_swap.b);
	return (0);
}