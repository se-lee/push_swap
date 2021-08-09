#include "push_swap.h"


// void	rotate_stack(t_stack *stack, int flag)
// {
// 	t_node	*temp;
// 	t_node	*top_next;

// 	if (stack->size < 2)
// 		return ;
// 	temp = stack->top;
// 	top_next = stack->top->next;
// 	stack->bottom->next = temp;
// 	temp->prev = stack->bottom;
// 	temp->next = NULL;
// 	stack->bottom = temp;
// 	stack->top = top_next;
// 	stack->top->prev = NULL;
// 	if (flag == A)
// 		ft_putendl_fd("ra", 1);
// 	else if (flag == B)
// 		ft_putendl_fd("rb", 1);
// }

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
