#include "push_swap.h"

void	sort_two_reverse_b(t_stack *b)
{
	if (b->top->content < b->top->next->content)
		op_swap_b(b);
}

void	b_three_top_min(t_stack *b)
{
	int	max;

	max = find_max_value_in_range(b->top, 3);
	if (b->top->next->content == max)
		op_rotate_b(b);
	else if (b->top->next->content != max)
	{
		op_rotate_b(b);
		op_swap_b(b);
	}		
}

void	b_three_top_mid(t_stack *b)
{
	if (b->top->content < b->top->next->content)
		op_swap_b(b);
	else if (b->top->content > b->top->next->content)
		op_reverse_rotate_b(b);
}

void	b_three_top_max(t_stack *b)
{
	int	mid;

	mid = find_mid_value_in_range(b->top, 3);
	if (b->top->next->content == mid)
		return ;
	else if (b->top->next->content != mid)
	{
		op_reverse_rotate_b(b);
		op_swap_b(b);
	}
}

void	sort_three_reverse_b(t_stack *b)
{
	int	min;
	int	mid;
	int	max;

	min = find_min_value_in_range(b->top, 3);
	mid = find_mid_value_in_range(b->top, 3);
	max = find_max_value_in_range(b->top, 3);
	if (stack_is_reverse_sorted(b))
		return ;
	if (b->top->content == min)
		b_three_top_min(b);
	else if (b->top->content == mid)
		b_three_top_mid(b);
	else if (b->top->content == max)
		b_three_top_max(b);
}

void	sort_four_reverse_b(t_stack *a, t_stack *b)
{
	int	max;
	int	pa_count;

	max = find_max_value_in_range(b->top, 4);
	pa_count = 0;
	while (b)
	{
		if (b->top->content == max)
		{
			op_push_to_a(b, a);
			pa_count++;
		}
		else
			op_rotate_b(b);
		if (pa_count == 1)
			break ;
	}
	sort_three_reverse_b(b);
	op_push_to_b(a, b);
}

void	push_back_a(t_stack *a, t_stack *b, int count)
{
	int	i;

	i = count;
	while (i > 0)
	{
		op_push_to_a(b, a);
		i--;
	}
}