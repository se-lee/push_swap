#include "push_swap.h"

void	pa(t_stack *stack_b, t_stack *stack_a)
{
	if (stack_a->top == NULL)
	{
		stack_a->top = stack_b->top;
		stack_b->top = stack_b->top->next;
		stack_b->top->prev = NULL;
		stack_a->top->next = NULL;
	}
	else
	{
		stack_a->top->prev = stack_b->top;
		stack_b->top = stack_b->top->next;
		stack_a->top->prev->next = stack_a->top;
		stack_a->top = stack_a->top->prev;
		if (stack_b->top->next == NULL)
			stack_b->top = NULL;
		stack_b->top->prev = NULL;
	}
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top == NULL)
	{
		stack_b->top = stack_a->top;
		stack_a->top = stack_a->top->next;
		stack_a->top->prev = NULL;
		stack_b->top->next = NULL;
	}
	else
	{
		stack_b->top->prev = stack_a->top;
		stack_a->top = stack_a->top->next;
		stack_b->top->prev->next = stack_b->top;
		stack_b->top = stack_b->top->prev;
		if (stack_a->top->next == NULL)
			stack_a->top = NULL;
		stack_a->top->prev = NULL;
	}
	ft_putendl_fd("pb", 1);
}

