#include "push_swap.h"

/*operations*/
//swap sa sb ss(sa&sb)
//push pb pa
//rotate ra rb rr(ra&rb)
//reverse rotate rra rrb rrr(rra&rrb)

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

void pop_and_push(t_stack *stack1, t_stack *stack2)
{//pop from stack1, push to stack2
	if (stack2->top == NULL)
	{//if stack2 is empty
		stack2->top = stack1->top;
		stack1->top = stack1->top->next;
		stack1->top->prev = NULL;
		stack2->top->next = NULL;
	}
	else
	{
		stack2->top->prev = stack1->top;
		stack1->top = stack1->top->next;
		stack2->top->prev->next = stack2->top;
		stack2->top = stack2->top->prev;
		stack2->top->next = stack2->top;
		stack1->top->prev = NULL;
	}
}

void rotate(t_stack *stack1);

void rev_rotate();

int main(int argc, char **argv)
{
	int i;
	t_stack	stack1;
	t_stack	stack2;

	i = 1;
	init_stack(&stack1);
	init_stack(&stack2);

	store_to_stack(argv, &stack1);
	printf("--before--\n");
	print_list(&stack1);
	printf("------\nstack1\n");
	print_list(&stack2);
	printf("------\nstack2\n\n");

pop_and_push(&stack1, &stack2);

	printf("--after--\n\n");
	print_list(&stack1);
	printf("------\nstack1\n");
	print_list(&stack2);
	printf("------\nstack2\n\n");

pop_and_push(&stack1, &stack2);

	printf("--after2--\n\n");
	print_list(&stack1);
	printf("------\nstack1\n");
	print_list(&stack2);
	printf("------\nstack2\n\n");

	return (0);
}