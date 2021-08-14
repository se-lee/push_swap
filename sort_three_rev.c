#include "push_swap.h"

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
	if (stack_b->top->content < stack_b->top->next->content)
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

void	b_sort_three(t_stack *b)
{
	int	min;
	int	mid;
	int	max;

	min = get_min_nbr(b);
	mid = get_mid_nbr(b->top, 3);
	max = get_max_nbr(b);
	if (is_sorted_reverse(b))
		return ;
	if (b->top->content == min)
		b_three_top_min(b);
	else if (b->top->content == mid)
		b_three_top_mid(b);
	else if (b->top->content == max)
		b_three_top_max(b);
}

void	b_sort_four(t_stack *a, t_stack *b)
{
	int	max;
	int	pa_count;

	max = get_max_nbr(b);
	pa_count = 0;
	while (b)
	{
		if (b->top->content == max)
		{
			pa(b, a);
			pa_count++;
		}
		else
			rb(b);
		if (pa_count == 1)
			break ;
	}
	b_sort_three(b);
	pb(a, b);
}

void	small_pa_back(t_stack *a, t_stack *b, int count)
{
	int	i;

	i = count;
	while (i > 0)
	{
		pa(b, a);
		i--;
	}
}