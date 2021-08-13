#include "push_swap.h"

/* function to sort three arguments in reverse order (for stack b) */

void	b_three_top_min(t_stack *stack_b)
{
	int	max;

	max = get_max_nbr(stack_b);
	if (stack_b->top->next->content == max)
		rb(stack_b);
	else if (stack_b->top->next->content != max)
	{
		rb(stack_b);
		sb(stack_b);
	}		
}

void	b_three_top_mid(t_stack *stack_b)
{
	if (stack_b->top->content < stack_b->top->next->content) //真ん中がMax
		sb(stack_b);
	else if (stack_b->top->content > stack_b->top->next->content)
		rrb(stack_b);
}

void	b_three_top_max(t_stack *stack_b)
{
	int	mid;

	mid = get_mid_nbr(stack_b->top, 3);
	if (stack_b->top->next->content == mid)
		return ;
	else if (stack_b->top->next->content != mid)
	{
		rrb(stack_b);
		sb(stack_b);
	}
}

void	b_sort_three(t_stack *stack_b)
{
	int	min;
	int	mid;
	int	max;

	min = get_min_nbr(stack_b);
	mid = get_mid_nbr(stack_b->top, 3);
	max = get_max_nbr(stack_b);

	if (check_rev_sorted(stack_b) == 0)
		return ;
	if (stack_b->top->content == min)
		b_three_top_min(stack_b);
	else if (stack_b->top->content == mid)
		b_three_top_mid(stack_b);
	else if (stack_b->top->content == max)
		b_three_top_max(stack_b);
}