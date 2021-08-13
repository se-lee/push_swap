/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:04:56 by selee             #+#    #+#             */
/*   Updated: 2021/08/13 13:01:48 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		range_is_sorted(t_stack *a, t_stack *b, int range, int a_b)
{
	if (range < 5)
	{
		if (a_b == A)
		{
			sort_less_five(a, b, range, A);
			return (1);
		}
		else if (a_b == B)
		{
			sort_less_five(a, b, range, B);
			return (1);
		}
	}
	return (0);
}

void	pb_small_ra(t_stack *a, t_stack *b, t_pivcount *pvcnt, int range)
{
	int		temp;

	temp = range;
 //printf("temp(range): %d    ", temp);

	while (temp > 0)
	{
		if (a->top->content <= pvcnt->pivot)
		{
			pb(a, b);
			pvcnt->pb++; //pb count will be the sorting range in b
		}
		else if (a->top->content > pvcnt->pivot)
		{
			ra(a);
			pvcnt->ra++;
		}
		temp--;
	}
	temp = pvcnt->ra;
	while (temp > 0)
	{
		rra(a);
		temp--;
	}
}

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

void	sort_a(t_stack *a, t_stack *b, int range)
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

void	sort_b(t_stack *a, t_stack *b, int range)
{
	t_pivcount pvcnt;
	int	temp;

	if (range <= 1)
		return ;
	if (range_is_sorted(a, b, range, B))
	{
		temp = range;
		while (temp > 0)
		{
			pa(b, a);
			temp--;
		}
		return ;
	}
	get_pivot(b->top, range, &pvcnt);
	pa_big_rb(a, b, &pvcnt, range);
	sort_a(a, b, pvcnt.pa);
	sort_b(a, b, pvcnt.rb);
}
