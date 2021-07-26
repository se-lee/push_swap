#include "push_swap.h"

/*operations*/
//swap sa sb ss
//push pb pa
//rotate ra rb rr
//reverse rotate rra rrb rrr

void swap(t_stack *stack, t_node *node1, t_node *node2)
{
	t_node *temp;

	node1->prev = node2;
	node1->next = node2->next;
	node2->prev = NULL;
	node2->next = node1;
	node2->next->prev = node1;
	stack->top = node2;
}

void pop(t_stack *stack);

void push_to(t_stack *stack1, t_stack *stack2);

void rotate();

void rev_rotate();


int main(int argc, char **argv)
{
	int i;
	t_stack	stack;

	i = 1;
	init_stack(&stack);
	store_to_stack(argv, &stack);
	print_list(&stack);
//	printf("\ncount: %d\n", stack.node_count);

	printf("------\n");
	swap(&stack, stack.top, stack.top->next);
	print_list(&stack);
//	printf("\ncount: %d\n", stack.node_count);

	return (0);
}