#include "push_swap.h"

/* op_push main */
int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	stack_init(&a);
	stack_init(&b);
	stack_store_value(argv, &a);

print_list(&a);
print_list(&b);

	op_push_to_b(&a, &b);
	op_push_to_b(&a, &b);
	
	op_push_to_a(&b, &a);
	op_push_to_a(&b, &a);

print_list(&a);
print_list(&b);

	return (0);

}

/* op_swap main */
int main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack stack_b;

	stack_init(&stack_a);
	stack_init(&stack_b);

	stack_store_value(argv, &stack_a);
	printf("before:\n");
	print_list(&stack_a);
	op_push_to_b(&stack_a, &stack_b);
	op_push_to_b(&stack_a, &stack_b);
	op_push_to_b(&stack_a, &stack_b);
	print_list(&stack_b);

printf("b_top: %d  ", stack_b.top->content);
printf("b_bottom: %d  \n", stack_b.bottom->content);

	op_swap_b(&stack_b);
	printf("after:\n");
	print_list(&stack_a);
	printf("a-top-prev: %p\n", stack_a.top->prev);
	printf("a-bttm-next: %p\n", stack_a.top->next->next);
	printf("a_count: %d\n", stack_a.node_count);
	printf("b_count: %d\n", stack_b.node_count);

	op_swap_a(&stack_a);
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

	stack_init(&a);
	stack_init(&b);
	stack_store_value(argv, &a);
	print_list(&a);
	print_list(&b);

	sort_five(&a, &b);

	printf("after:\n");
	print_list(&a);
	print_list(&b);

	return (0);
}


int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return 0;
	stack_init(&a, &b);
	stack_store_value(argv, &a);
	print_list(&a, A);
	print_list(&b, B);

	sort_less_five(&a, &b, 4, B);

	printf("after:\n");
	print_list(&a, A);
	print_list(&b, B);

	return (0);
}