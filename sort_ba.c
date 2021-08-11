#include "push_swap.h"

int		b_to_a_exception(t_stack *stack_a, t_stack *stack_b, int range)
{
	if (range <= 3)
	{
		sort_less_five(stack_a, stack_b, range, B);
		return (0);
	}
	else if (range == 5)
	{
		sort_five()
	}
}


void	b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cursor;
	t_pivcount	pvcnt;
	int		temp;

	get_pivot(stack_b->top, stack_b->node_count, &pvcnt);
	cursor = stack_b->top;
	temp = stack_b->node_count;
	while (temp > 0)
	{
		if (stack_b->top->content > pvcnt.piv_big)
			pa(stack_b, stack_a);
		else
			rb(stack_b);
	}

}

void	b_rotate_push(t_stack *stack_a, t_stack *stack_b, t_pivcount *pvcnt)
{
	if (stack_b->top->content > pvcnt->piv_small)
	{
		pa(stack_b, stack_a);
		pvcnt->pa++;
		if (stack_a->top->content <= pvcnt->piv_big)
		{
			ra(stack_a);
			pvcnt->ra++;
		}
	}
	else
	{
		rb(stack_b);
		pvcnt->rb++;
	}
}

void	back_rotate_btoa(t_stack *stack_a, t_stack *stack_b, t_pivcount *pvcnt)
{
	int	rrr_cnt;
	int	diff;

	rrr_cnt = pvcnt->rb;
	diff = pvcnt->ra - rrr_cnt;
	while (rrr_cnt > 0)
	{
		rrr(stack_a, stack_b);
		rrr_cnt--;
	}	
	while (diff > 0)
	{
		rra(stack_a);
		diff--;
	}
}

void	back_rotate_atob(t_stack *stack_a, t_stack *stack_b, t_pivcount *pvcnt)
{
	int	rrr_cnt;
	int	diff;

	rrr_cnt = pvcnt->ra;
	diff = pvcnt->rb - rrr_cnt;

	while (rrr_cnt > 0)
	{
		rrr(stack_a, stack_b);
		rrr_cnt--;
	}
	while (diff > 0)
	{
		rb(stack_b);
		diff--;
	}
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b, int range, int *cnt)
{
	int	temp;
	t_pivcount	pvcnt;

	(*cnt)++;
	
	init_op_count(&pvcnt);
	get_pivot(stack_b->top, range, &pvcnt);
	temp = range;
	while (temp > 0)
	{
		b_rotate_push(stack_a, stack_b, &pvcnt);
		temp--;
	}
	a_to_b(stack_a, stack_b, pvcnt.pa - pvcnt.ra, cnt);
	if (pvcnt.ra > pvcnt.rb)
		back_rotate_btoa(stack_a, stack_b, &pvcnt);
	else
		back_rotate_atob(stack_a, stack_b, &pvcnt);
	a_to_b(stack_a, stack_b, pvcnt.ra, cnt);
	b_to_a(stack_a, stack_b, pvcnt.rb, cnt);

}

