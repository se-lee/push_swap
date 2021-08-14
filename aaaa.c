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

	pivot = get_pivot(a->top, range);
printf("pivot a: %d  ", pivot);
	temp = range;
	while (range--)
	{
		if (a->top->content <= pivot)
		{
			pb(a, b);
			count.pb++;
		}
		else
		{
			ra(a);
			count.ra++;
		}
	}
	temp = count.ra;
	while (temp--)
		rra(a);
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

	pivot = get_pivot(b->top, range);
printf("pivot b: %d \n", pivot);
	temp = range;
	while (temp--)
	{
		if (b->top->content > pivot)
		{
			pa(b, a);
			count.pa++;
		}
		else
		{
			rb(b);
			count.rb++;
		}
	}
	temp = count.rb;
	while (temp--)
		rrb(b);
	return (count);
}

/* sort range (small) */
int		sort_range(t_stack *a, int range)
{
	if (range == 2)
	{
		sort_two_stack_a(a);
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
		sort_two_reverse_stack_b(b);
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
	quick_sort_a(a, b, count.ra);
	quick_sort_b(a, b, count.pb);
	while (count.pb--)
		pa(b, a);
}

void	quick_sort_b(t_stack *a, t_stack *b, int range)
{
	t_pivcount	count;

	if (range <= 1)
		return ;
	if (sort_range_reverse(b, range))
		return ;
	count = partition_b_in_range(a, b, range);
	quick_sort_a(a, b, count.pa);
	quick_sort_b(a, b, count.rb);

}
