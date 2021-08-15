#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	int	i;

	i = 0;
	printf("argc: %d\n", argc);
	while (i < argc)
	{
		printf("argv[%d] %s \n", i, argv[i]);
		i++;
	}

	if (argc <= 1)
		return (0);

	if (!arg_is_int(argv))
		print_error_exit();
	stack_init(&a);
	stack_store_value(argv, &a);
	if (stack_has_duplicate(&a))
		print_error_exit();
	stack_init(&b);

//	push_swap(&a, &b);

// /* -------> erase below <-------*/	
	print_list(&a, 'a');
	print_list(&b, 'b');
// /* -------> erase erase <-------*/		

	return (0);
}
