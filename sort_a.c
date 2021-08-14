/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:36:28 by selee             #+#    #+#             */
/*   Updated: 2021/08/14 16:04:44 by selee            ###   ########lyon.fr   */
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
		pb(a, b);
		pvcnt->pb++;
	}
	else if (a->top->content > pvcnt->pivot)
	{
		ra(a);
		pvcnt->ra++;
	}
	temp = pvcnt->ra;
	while (temp > 0)
	{
		rra(a);
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
	get_pivot(a->top, range, &pvcnt);
	temp = range;
	while (temp--)
		pb_small_ra(a, b, &pvcnt);
	sort_a(a, b, pvcnt.ra);
	sort_b(a, b, pvcnt.pb);
	while (pvcnt.pb--)
		pa(b, a);
}
