#include "push_swap.h"

void	pop_push_min(t_stack *stack1, t_stack *stack2)
{
	int		min;
	t_node	*cursor;
	int		position;
	int		min_position;

	cursor = stack1->top;
	min = cursor->content;
	position = 1;
	while (cursor->next != NULL)
	{	
		position++;
		if (cursor->next->content < min)
		{
			min = cursor->next->content;
			min_position = position;
		}
		cursor = cursor->next;
	}
	while (min_position > 1)
	{
		rotate(stack1);
		min_position--;
	}
	pop_and_push(stack1, stack2);
}

void	select_sort_list(t_stack *stack1, t_stack *stack2)
{
	while (stack1->top != stack1->bottom)
	{
		pop_push_min(stack1, stack2);
	}
	while (stack2->top != NULL)
	 	pop_and_push(stack2, stack1);
}

int main(int argc, char **argv)
{
	int i;
	t_stack	stack1;
	t_stack	stack2;


	i = 1;
	init_stack(&stack1);
	init_stack(&stack2);
	store_to_stack(argv, &stack1);

	print_list(&stack1);
	printf("------\nstack1\n");
	print_list(&stack2);
	printf("------\nstack2\n\n");

	select_sort_list(&stack1, &stack2);
	printf("-------------------------\n");
	print_list(&stack1);
	printf("------\nstack1_after\n");
	print_list(&stack2);
	printf("------\nstack2_after\n\n");
//	printf("top: %d\nbottom: %d", stack1.top->content, stack1.bottom->content);
	return (0);
}
