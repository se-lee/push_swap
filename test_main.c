#include "push_swap.h"

/* op_push main */
int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init_stack(&a);
	init_stack(&b);
	store_to_stack(argv, &a);

print_list(&a);
print_list(&b);

	pb(&a, &b);
	pb(&a, &b);
	
	pa(&b, &a);
	pa(&b, &a);

print_list(&a);
print_list(&b);

	return (0);

}

/* op_swap main */
int main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack stack_b;

	init_stack(&stack_a);
	init_stack(&stack_b);

	store_to_stack(argv, &stack_a);
	printf("before:\n");
	print_list(&stack_a);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	print_list(&stack_b);

printf("b_top: %d  ", stack_b.top->content);
printf("b_bottom: %d  \n", stack_b.bottom->content);

	sb(&stack_b);
	printf("after:\n");
	print_list(&stack_a);
	printf("a-top-prev: %p\n", stack_a.top->prev);
	printf("a-bttm-next: %p\n", stack_a.top->next->next);
	printf("a_count: %d\n", stack_a.node_count);
	printf("b_count: %d\n", stack_b.node_count);

	sa(&stack_a);
	print_list(&stack_a);
	print_list(&stack_b);

	return (0);
}


/* rotate main */
// int main(int argc, char **argv)
// {
// 	t_stack a;
// 	t_stack	b;

// 	init_stack(&a);
// 	init_stack(&b);
// 	store_to_stack(argv, &b);
// 	print_list(&b);

// 	rb(&b);
// 	rb(&b);
// 	print_list(&b);

// 	return (0);
// }

/* sort_five main */
int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int	mid;

	init_stack(&a);
	init_stack(&b);
	store_to_stack(argv, &a);
	print_list(&a);
	print_list(&b);

	sort_five(&a, &b);

	printf("after:\n");
	print_list(&a);
	print_list(&b);

	return (0);
}
