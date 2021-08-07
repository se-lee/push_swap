#include "push_swap.h"

void ra(t_stack *stack)
{
	stack->top->prev = stack->bottom;
	stack->bottom->next = stack->top;
	stack->top->next->prev = NULL;
	stack->bottom = stack->top;
	stack->top = stack->bottom->next;
	stack->bottom->next = NULL;
	ft_putendl_fd("ra", 1);
}

void rb(t_stack *stack)
{
	stack->top->prev = stack->bottom;
	stack->bottom->next = stack->top;
	stack->top->next->prev = NULL;
	stack->bottom = stack->top;
	stack->top = stack->bottom->next;
	stack->bottom->next = NULL;
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_putendl_fd("rr", 1);
}

void	rra(t_stack *stack)
{
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->top = stack->bottom;
	stack->bottom = stack->top->prev;
	stack->bottom->next = NULL;
	stack->top->prev = NULL;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *stack)
{
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->top = stack->bottom;
	stack->bottom = stack->top->prev;
	stack->bottom->next = NULL;
	stack->top->prev = NULL;
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_putendl_fd("rrr", 1);
}