/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:36:28 by selee             #+#    #+#             */
/*   Updated: 2021/08/15 12:38:40 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		range_is_sorted(t_stack *a, t_stack *b, int range, int a_b)
{
	if (range < 5)
	{
		if (a_b == A)
			sort_less_five(a, b, range, A);
		else if (a_b == B)
			sort_less_five(a, b, range, B);
		return (1);
	}
	return (0);
}

// push rotate and reverse
void	pb_small_ra(t_stack *a, t_stack *b, t_pivcount *pvcnt) // revise name and what it does
{
	int		temp;

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
	temp = pvcnt->ra_count;
	while (temp > 0)
	{
		op_reverse_rotate_a(a);
		temp--;
	}
}


void	sort_a(t_stack *a, t_stack *b, int range)
{
	t_pivcount	pvcnt;
	int	temp;

	if (range <= 1)
		return ;
	if (range_is_sorted(a, b, range, A))
		return ;
	init_op_count(&pvcnt);
	find_pivot(a->top, range, &pvcnt);
	temp = range;
	while (temp--)
		pb_small_ra(a, b, &pvcnt);
	sort_a(a, b, pvcnt.ra_count);
	sort_b(a, b, pvcnt.pb_count);
	while (pvcnt.pb_count--)
		op_push_to_a(b, a);
}
