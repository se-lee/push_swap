/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:36:28 by selee             #+#    #+#             */
/*   Updated: 2021/08/15 12:38:40 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_small_ra2(t_stack *a, t_stack *b, t_pivcount *pvcnt, int range)
{
	if (a->top->content <= pvcnt->pivot)
	{
		op_push_to_b(a, b);
		pvcnt->pb_count++;
	}
	else if (a->top->content > pvcnt->pivot)
	{
		op_rotate_a(a);
		pvcnt->ra_count++;
	}
}

void	sort_a2(t_stack *a, t_stack *b, int range)
{
	t_pivcount	pvcnt;

	if (range <= 1)
		return ;
	if (range_is_sorted(a, b, range, A))
		return ;
	init_op_count(&pvcnt);
	find_pivot(a->top, range, &pvcnt);
	pb_small_ra(a, b, &pvcnt, range);
	sort_a(a, b, pvcnt.ra_count);
	sort_b(a, b, pvcnt.pb_count);
}