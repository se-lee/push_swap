#include "push_swap.h"
#include <stdio.h>


void	selection_sort_list(t_stack *stack1, t_stack *stack2)
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
printf("min_pos: %d\n", min_position);
	while (min_position > 1)
	{
		rotate(stack1);
		min_position--;
	}
	pop_and_push(stack1, stack2);
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

	print_list(&stack1);
	printf("------\nstack1_after\n");
	printf("top: %d\nbottom: %d", stack1.top->content, stack1.bottom->content);
	return (0);
}

/*
how to decide the operation?

- check min number
- get the position of the min number
- rotate until the min number becomes stack->top
- then do pb

- once stack has only one number, do pa until stack b is empty


how to get the position in the linked list?
- t_node *temp variable, pointing to the position of nodes
- int position variable to tell which position you want to go 
	(how many steps you want the temp variable to take)
*/
