#include "push_swap.h"

/*prep*/
//store each argument to each node and put them into stack a
// a function to do atoi and store the value to each node;

void add_to_stack_back(t_stack *stack, t_node *new_node)
{
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->bottom = new_node;
		stack->node_count++;
	}
	else
	{
		new_node->prev = stack->bottom;
		stack->bottom = new_node;
		stack->node_count++;
	}
}

void	print_list(t_stack *stack)
{
	t_node *node;

	node = stack->top;
	while (node != NULL)
	{
		printf("%d ", node->content);
		node = node->next;
	}
}

int main(int argc, char **argv)
{
	int i;
	t_stack *stack;
	int test;

	i = 1;
	while (argv[i] != NULL)
	{
		printf("arg[%d]str: %s\n", i, argv[i]);
		i++;
	}
	printf("test %d, %d ", ft_atoi(argv[1]), ft_atoi(argv[2]));
	
	init_stack(stack);
	i = 0;
	while (argv[i] != NULL)
	{
		add_to_stack_back(stack, ft_new_node(ft_atoi(argv[i])));
		i++;
	}
	add_to_stack_back(stack, ft_new_node(ft_atoi(argv[i])));
	print_list(stack);
	printf("stack size: %d\n", stack->node_count);

	return (0);	
}


