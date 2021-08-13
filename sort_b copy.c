/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:36:14 by selee             #+#    #+#             */
/*   Updated: 2021/08/13 16:09:02 by selee            ###   ########lyon.fr   */
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
			pa(b, a);
			pvcnt->pa++;
		}
		else
		{
			rb(b);
			pvcnt->rb++;
		}
		temp--;
	}
	temp = pvcnt->rb;
	while (temp > 0)
	{
		rrb(b);
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
	get_pivot(b->top, range, &pvcnt);
	pa_big_rb(a, b, &pvcnt, range);
	sort_a(a, b, pvcnt.pa);
	sort_b(a, b, pvcnt.rb);
}

