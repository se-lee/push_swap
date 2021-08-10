/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:26:11 by selee             #+#    #+#             */
/*   Updated: 2021/08/10 04:15:56 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_op_count(t_opcount *count)
{
	count->pa = 0;
	count->pb = 0;
	count->ra = 0;
	count->rb = 0;
}

void	a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node		*cursor;
	t_pivot 	pv;
	t_opcount	count;

	pv = get_pivot(stack_a->top, stack_a->node_count);
	init_op_count(&count);
	cursor = stack_a->top;
	
	while (cursor->next != NULL)
	{
		if (cursor->content <= pv.piv_small)
			pb(stack_a, stack_b);
		else if (cursor->content > pv.piv_big)
			ra(stack_a);
		cursor = cursor->next;
	}
}


