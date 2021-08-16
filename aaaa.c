#include "push_swap.h"

int		sort_range(t_stack *a, t_stack *b, int range)
{
	if (range < 3)
	{
		sort_less_five_a(a, b, range);
		return 1;
	}
	return 0;
}

int		sort_range_reverse(t_stack *b, int range)
{
	if (range == 2)
	{
		sort_two_reverse_b(b);
		return 1;
	}
	else if (range == 3)
	{
		sort_three_reverse_b(b);
		return 1;
	}
	return 0;
}

t_op_count	partition_a_in_range(t_stack *a, t_stack *b, int range)
{
	int	pivot;
	int	temp;
	t_op_count	count;

	pivot = find_mid_value_in_range(a->top, range);
	init_op_count(&count);
	temp = range;
	while (temp--)
	{
		if (a->top->content <= pivot)
		{
			op_push_to_b(a, b);
			count.pb_count++;
		}
		else
		{
			op_rotate_a(a);
			count.ra_count++;
		}
	}
debug(printf, "[pivot a]: %d \n", pivot);
debug(printf, "[A_range]]: %d \n", range);
debug(printf, "[ra count]: %d \n\n", count.ra_count);
	if (count.ra_count != a->node_count)
	{
		temp = count.ra_count;
		while (temp--)
			op_reverse_rotate_a(a);
	}
debug(printf, "--part.A--\n");
debug(print_list, a, 'a');
debug(print_list, b, 'b');
	return (count);
}

/*
divide set of numbers (b) into half
bigger numbers move to A, smaller numbers stay in b
*/

#include <assert.h>

t_op_count	partition_b_in_range(t_stack *a, t_stack *b, int range)
{
	int	pivot;
	int	temp;
	t_op_count count;

	pivot = find_mid_value_in_range(b->top, range);
	init_op_count(&count);
	temp = range;
	while (temp--)
	{
		if (b->top->content >= pivot)
		{
			op_push_to_a(b, a);
			count.pa_count++;
		}
		else
		{
			op_rotate_b(b);
			count.rb_count++;
		}
	}
debug(printf, "[pivot b]: %d \n", pivot);
debug(printf, "[B_range]]: %d \n", range);
debug(printf, "[rb count]: %d \n\n", count.rb_count);
	if (count.rb_count != b->node_count)
	{
		temp = count.rb_count;
		while (temp--)
			op_reverse_rotate_b(b);
	}
	return (count);
}

void	quick_sort_a(t_stack *a, t_stack *b, int range)
{
	t_op_count count;

	if (range <= 1 || stack_is_sorted(a))
		return ;
	if (range == 2)
		return (sort_two_a(a));
	if (range == 3)
		return (sort_a_3(a));
	count = partition_a_in_range(a, b, range);
	quick_sort_a(a, b, count.ra_count);
	quick_sort_b(a, b, count.pb_count);
debug(printf, "[pb_count(merge)]: %d \n", count.pb_count);
debug(print_list, b, 'b');
	while (count.pb_count--)
		op_push_to_a(b, a);
}

void	quick_sort_b(t_stack *a, t_stack *b, int range)
{
	t_op_count	count;

	if (range <= 1 || stack_is_reverse_sorted(b))
		return ;
	if (range == 2)
		return (sort_two_reverse_b(b));
	if (range == 3)
		return (sort_b_3(b));
	count = partition_b_in_range(a, b, range);
	quick_sort_b(a, b, count.rb_count);
	quick_sort_a(a, b, count.pa_count);
	while (count.pa_count--)
		op_push_to_b(a, b);
}