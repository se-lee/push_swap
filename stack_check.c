#include "push_swap.h"

int		stack_has_duplicate(t_stack *stack)
{
	int	value;
	t_node	*cursor;

	while (stack)
	{
		cursor = stack->top->next;
		value = stack->top->content;
		while (cursor)
		{
			if (cursor->content == value)
				return (1);
			if (cursor->next)
				cursor = cursor->next;
			else
				break;
		}
		stack->top = stack->top->next;
	}
	return (0);
}

int	stack_is_sorted(t_stack *stack)
{
	t_node	*cursor;

	cursor = stack->top;
	while (cursor->next != NULL)
	{
		if (cursor->content > cursor->next->content)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}

int	stack_is_reverse_sorted(t_stack *stack)
{
	t_node *cursor;

	cursor = stack->top;
	while (cursor != NULL && cursor->next != NULL)
	{
		if (cursor->content < cursor->next->content)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}