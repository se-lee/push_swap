#include "push_swap.h"

void init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->node_count = 0;
}

void add_to_stack(t_stack *stack, t_node *new_node) //push (add on top)
{
	if (stack->top == NULL)
		stack->top = new_node;
	else
	{
		new_node->next = stack->top;
		stack->top->prev = new_node;
		stack->top = new_node;
	}
}

void add_to_stack_back(t_stack *stack, t_node *new_node) //add to the back(bottom)
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
		stack->bottom->next = new_node;
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
		printf("stack: %d \n", node->content);
		node = node->next;
	}
}

