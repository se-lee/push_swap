/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:26:11 by selee             #+#    #+#             */
/*   Updated: 2021/08/11 04:06:57 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_op_count(t_pivcount *count)
{
	count->pa = 0;
	count->pb = 0;
	count->ra = 0;
	count->rb = 0;
}

void	divide_big_piv(t_stack *stack_a, t_stack *stack_b, t_pivcount *pvcnt)
{
	if (stack_a->top->content <= pvcnt->piv_big) //send numbers smaller/equal to big pivot
	{
		pb(stack_a, stack_b);
		pvcnt->pb++;
	// 	if (stack_b->top->content < pvcnt->piv_small) //move smaller nbrs on the back of list b
	// 	{
	// 		rb(stack_b);
	// 		pvcnt->rb++;
	// 	}
	}
	else if (stack_a->top->content > pvcnt->piv_big)
	{
		ra(stack_a);
		pvcnt->ra++;
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
	a_to_b(stack_a, stack_b);
	b_to_a(stack_a, stack_b);
}

/*
void	rotate_back_a(t_stack *stack_a, t_stack *stack_b, int *count, t_pivcount *pvcnt)
{
	int	rrr_cnt;
	int	diff;

	rrr_cnt = pvcnt->rb;
	diff = pvcnt->ra - rrr_cnt;
	if ((*count) > 0)
	{
		while (rrr_cnt > 0)
		{
			rrr(stack_a, stack_b);
			rrr_cnt--;
		}
		while (diff > 0)
		{
			ra(stack_a);
			diff--;
		}
	}
	else
	{
		while (rrr_cnt > 0)
		{
			rb(stack_b);
		}
	}
}
*/

void	a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node		*cursor;
	t_pivcount	pvcnt;
	int			temp;

	get_pivot(stack_a->top, stack_a->node_count, &pvcnt);
	init_op_count(&pvcnt);
	printf("bp: %d  sp: %d\n", pvcnt.piv_big, pvcnt.piv_small);
	cursor = stack_a->top;
	temp = stack_a->node_count;
	while (temp > 0)
	{
		divide_big_piv(stack_a, stack_b, &pvcnt);
		temp--;
	}
	a_to_b(stack_a, stack_b);
	b_to_a(stack_a, stack_b);
}
