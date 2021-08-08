#include "push_swap.h"

/*
get min nbr
if top is min push to b
*/
void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	t_node	*cursor;
	
	min = get_min_nbr(stack_a);
	cursor = stack_a->top;

	
	

}


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


}

