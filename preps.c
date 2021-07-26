#include "push_swap.h"

void	store_to_stack(char **argv)
{
	int i;
	t_stack stack;

	init_stack(&stack);
	i = 1;
	while (argv[i] != NULL)
	{
		add_to_stack_back(&stack, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}



