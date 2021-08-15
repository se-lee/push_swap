/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:36:14 by selee             #+#    #+#             */
/*   Updated: 2021/08/15 23:38:08 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_big_rb(t_stack *a, t_stack *b, t_pivcount *pvcnt)
{
	int	temp;
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
	temp = pvcnt->rb_count;
	while (temp > 0)
	{
		op_reverse_rotate_b(b);
		temp--;
	}
}

void	sort_b(t_stack *a, t_stack *b, int range)
{
	t_pivcount	pvcnt;
	int			temp;

	if (range <= 1)
		return ;
	if (sort_range(a, b, range, B))
		return ;
	find_pivot(b->top, range, &pvcnt);
	temp = range;
	while (temp > 0)
	{
		pa_big_rb(a, b, &pvcnt);
		temp--;
	}
	sort_a(a, b, pvcnt.pa_count);
	sort_b(a, b, pvcnt.rb_count);
}
