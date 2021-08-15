/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:36:14 by selee             #+#    #+#             */
/*   Updated: 2021/08/15 12:38:38 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_big_rb(t_stack *a, t_stack *b, t_pivcount *pvcnt, int range)
{
	int	temp;

	temp = range;
	while (temp > 0)
	{
		if (b->top->content > pvcnt->pivot)
		{
			op_push_to_a(b, a);
			pvcnt->pa_count++;
		}
		else
		{
			op_rotate_b(b);
			pvcnt->rb_count++;
		}
		temp--;
	}
	temp = pvcnt->rb_count;
	while (temp > 0)
	{
		op_reverse_rotate_b(b);
		temp--;
	}
}

void	sort_b(t_stack *a, t_stack *b, int range)
{
	t_pivcount pvcnt;

	if (range <= 1)
		return ;
	if (range_is_sorted(a, b, range, B))
		return ;
	find_pivot(b->top, range, &pvcnt);
	pa_big_rb(a, b, &pvcnt, range);
	sort_a(a, b, pvcnt.pa_count);
	sort_b(a, b, pvcnt.rb_count);
}

