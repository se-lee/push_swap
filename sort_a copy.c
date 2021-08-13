/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:36:28 by selee             #+#    #+#             */
/*   Updated: 2021/08/13 16:47:48 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_small_ra2(t_stack *a, t_stack *b, t_pivcount *pvcnt, int range)
{
	if (a->top->content <= pvcnt->pivot)
	{
		pb(a, b);
		pvcnt->pb++;
	}
	else if (a->top->content > pvcnt->pivot)
	{
		ra(a);
		pvcnt->ra++;
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
	get_pivot(a->top, range, &pvcnt);
	pb_small_ra(a, b, &pvcnt, range);
	sort_a(a, b, pvcnt.ra);
	sort_b(a, b, pvcnt.pb);
}