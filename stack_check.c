#include "push_swap.h"

int		stack_has_duplicate(t_stack *stack)
{
	t_node	*cursor;
	t_node	*cursor_2;

	cursor = stack->top;
	while (cursor)
	{
		cursor_2 = cursor->next;
		while (cursor_2)
		{
			if (cursor_2->content == cursor->content)
				return (1);
			cursor_2 = cursor_2->next;
		}
		cursor = cursor->next;
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