#include "push_swap.h"

void add_to_stack_back(t_stack *stack, t_node *new_node)
{
	t_node *cursor;

	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->bottom = new_node;
		stack->node_count++;
	}
	else
	{
		cursor = stack->top;
		while (cursor->next != NULL)
			cursor = cursor->next;
		new_node->prev = stack->bottom;
		cursor->next = new_node;
		new_node->prev = cursor;
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
		printf("stack: %d \n", node->content);
		node = node->next;
	}
}

int main(int argc, char **argv)
{
	int i;
	t_stack stack;

	i = 1;
	while (argv[i] != NULL)
	{
		printf("arg[%d]str: %s\n", i, argv[i]);
		i++;
	}

	printf("node1: %d\n", (ft_lstnew(ft_atoi(argv[1]))->content));
	printf("node2: %d\n", (ft_lstnew(ft_atoi(argv[2]))->content));
	printf("node3: %d\n", (ft_lstnew(ft_atoi(argv[3]))->content));
	printf("node4: %d\n", (ft_lstnew(ft_atoi(argv[4]))->content));
	printf("node5: %d\n", (ft_lstnew(ft_atoi(argv[5]))->content));

	init_stack(&stack);
	i = 1;
	while (argv[i] != NULL)
	{
		add_to_stack_back(&stack, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	print_list(&stack);
	printf("count: %d\n", stack.node_count);

	return (0);	
}


