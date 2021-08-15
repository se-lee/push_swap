#include "push_swap.h"

/*
the purpose is to divide the number set (stack a) into two groups within a range, 
one group will be bigger half
the other smaller half
"filter out half of the values, so that the large numbers "
"split A in half within range"
- push rotate reverse count-operation move-small-numbers
 "partition_a_in_range"

*/

t_pivcount	partition_a_in_range(t_stack *a, t_stack *b, int range)
{
	int	pivot;
	int	temp;
	t_pivcount	count;

	pivot = find_mid_value_in_range(a->top, range);
printf("pivot a: %d  ", pivot);
	temp = range;
	while (range--)
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
	temp = count.ra_count;
	while (temp--)
		op_reverse_rotate_a(a);
	return (count);
}

/*
divide set of numbers (b) into half
bigger numbers move to A, smaller numbers stay in b
*/

t_pivcount	partition_b_in_range(t_stack *a, t_stack *b, int range)
{
	int	pivot;
	int	temp;
	t_pivcount count;

	pivot = find_mid_value_in_range(b->top, range);
printf("pivot b: %d \n", pivot);
	temp = range;
	while (temp--)
	{
		if (b->top->content > pivot)
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
	temp = count.rb_count;
	while (temp--)
		op_reverse_rotate_b(b);
	return (count);
}

/* sort range (small) */
int		sort_range(t_stack *a, int range)
{
	if (range == 2)
	{
		sort_two_a(a);
//maybe add more number (later)
		return (1);
	}
	return (0);
}

/* reverse sort (small) range */
int		sort_range_reverse(t_stack *b, int range)
{
	if (range == 2)
	{
		sort_two_reverse_b(b);
		return (1);
	}
	return (0);
}

void	quick_sort_a(t_stack *a, t_stack *b, int range)
{
	t_pivcount count;

	if (range <= 1)
		return ;
	if (sort_range(a, range))
		return ;
	init_op_count(&count);
	count = partition_a_in_range(a, b, range);
printf("range: %d  ", range);
	quick_sort_a(a, b, count.ra_count);
	quick_sort_b(a, b, count.pb_count);
	while (count.pb_count--)
		op_push_to_a(b, a);
}

void	quick_sort_b(t_stack *a, t_stack *b, int range)
{
	t_pivcount	count;

	if (range <= 1)
		return ;
	if (sort_range_reverse(b, range))
		return ;
	count = partition_b_in_range(a, b, range);
	quick_sort_a(a, b, count.pa_count);
	quick_sort_b(a, b, count.rb_count);

}
