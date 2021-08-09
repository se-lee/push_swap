#include "push_swap.h"

void	three_args_top_min(t_stack *stack)
{
	rra(stack);
	sa(stack);
}

void	three_args_top_mid(t_stack *stack)
{
	if (stack->top->next->content < stack->top->content)
		sa(stack);
	else if (stack->top->next->content > stack->top->content)
		rra(stack);
}

void	three_args_top_max(t_stack *stack)
{
	int	min;

	min = get_min_nbr(stack);
	if (stack->top->next->content == min)
		ra(stack);
	else if (stack->top->next->content != min)
	{
		ra(stack);
		sa(stack);
	}
}

void	sort_three_args(t_stack *stack)
{
	int	min;
	int	mid;
	int	max;

	min = get_min_nbr(stack);
	mid = get_mid_nbr(stack->top, 3);
	max = get_max_nbr(stack);
	if (check_sorted(stack) == 0)
		return ;
	if (stack->top->content == min)
		three_args_top_min(stack);
	else if (stack->top->content == mid)
		three_args_top_mid(stack);
	else if (stack->top->content == max)
		three_args_top_max(stack);
}

