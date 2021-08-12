#include "push_swap.h"

/*
pb all smaller&equal numbers than pivot
sort a (and forget everthing under) small->big
sort b big->small

once two stacks are sorted, do pa
try not to touch other parts
* i need to know from where to where (= the range of the part i want to take care of) 
reset
-> count the number of ra then do rra
-> count the number of rb, then do rrb
*/

int		range_is_sorted(t_stack *stack_a, t_stack *stack_b, int range, int a_or_b)
{
	if (range < 5)
	{
		if (a_or_b == A)
		{
			sort_less_five(stack_a, stack_b, range, A);
			return (1);
		}
		else if (a_or_b == B)
		{
			sort_less_five(stack_a, stack_b, range, B);
			return (1);
		}
	}
	return (0);
}

void	pb_small_ra(t_stack *stack_a, t_stack *stack_b, t_pivcount *pvcnt, int range)
{
	int		temp;

	temp = range;
 //printf("temp(range): %d    ", temp);

	while (temp > 0)
	{
		if (stack_a->top->content <= pvcnt->pivot)
		{
			pb(stack_a, stack_b);
			pvcnt->pb++; //pb count will be the sorting range in stack_b
		}
		else if (stack_a->top->content > pvcnt->pivot)
		{
			ra(stack_a);
			pvcnt->ra++;
		}
		temp--;
	}
	temp = pvcnt->ra;
	while (temp > 0)
	{
		rra(stack_a);
		temp--;
	}
}

void	pa_big_rb(t_stack *stack_a, t_stack *stack_b, t_pivcount *pvcnt, int range)
{
	int	temp;

	temp = range;
	while (temp > 0)
	{
		if (stack_b->top->content > pvcnt->pivot)
		{
			pa(stack_b, stack_a);
			pvcnt->pa++;
		}
		else
		{
			rb(stack_b);
			pvcnt->rb++;
		}
		temp--;
	}
	temp = pvcnt->rb;
	while (temp > 0)
	{
		rrb(stack_b);
		temp--;
	}
}


void	sort_a(t_stack *stack_a, t_stack *stack_b, int range)
{
	t_pivcount	pvcnt;

	if (range <= 1)
		return ;
	if (range_is_sorted(stack_a, stack_b, range, A))
		return ;
	init_op_count(&pvcnt);
	get_pivot(stack_a->top, range, &pvcnt);
	pb_small_ra(stack_a, stack_b, &pvcnt, range);
	sort_a(stack_a, stack_b, pvcnt.ra);
	sort_b(stack_a, stack_b, pvcnt.pb);
}

void	sort_b(t_stack *stack_a, t_stack *stack_b, int range)
{
	t_pivcount pvcnt;
	int	temp;

	if (range <= 1)
		return ;
	if (range_is_sorted(stack_a, stack_b, range, B))
	{
		temp = range;
		while (temp > 0)
		{
			pa(stack_b, stack_a);
			temp--;
		}
		return ;
	}
	get_pivot(stack_b->top, range, &pvcnt);
	pa_big_rb(stack_a, stack_b, &pvcnt, range);
	sort_a(stack_a, stack_b, pvcnt.pa);
	sort_b(stack_a, stack_b, pvcnt.rb);
}
