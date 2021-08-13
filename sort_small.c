/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:26:03 by selee             #+#    #+#             */
/*   Updated: 2021/08/13 15:46:18 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_sort_four(t_stack *a, t_stack *b)
{
	int	mid;
	int	pb_count;

	mid = get_mid_nbr(a->top, 4);
	pb_count = 0;
	while (a)
	{
		if (a->top->content < mid)
		{
			pb(a, b);
			pb_count++;
		}
		else
			ra(a);
		if (pb_count == 1)
			break ;
	}
	a_sort_three(a);
	pa(b, a);
	if (a->top->content > a->top->next->content)
		sa(a);
}

void	b_sort_four(t_stack *a, t_stack *b)
{
	int	max;
	int	pa_count;

	max = get_max_nbr(b);
	pa_count = 0;
	while (b)
	{
		if (b->top->content == max)
		{
			pa(b, a);
			pa_count++;
		}
		else
			rb(b);
		if (pa_count == 1)
			break ;
	}
	b_sort_three(a, b);
	pb(a, b);
}

void	sort_less_five(t_stack *a, t_stack *b, int count, int a_b)
{
	if (a_b == A)
	{
		if (count == 1)
			return ;
		else if (count == 2)
			sort_two(a, b, A);
		else if (count == 3)
			a_sort_three(a);
		else if (count == 4)
			a_sort_four(a, b);
	}
	else if (a_b == B)
	{
		if (count == 1)
			return ;
		else if (count == 2)
			sort_two(a, b, B);
		else if (count == 3)
			b_sort_three(a, b);
		else if (count == 4)
			b_sort_four(a, b);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	mid;
	int	pb_count;

	mid = get_mid_nbr(a->top, a->node_count);
	pb_count = 0;
	while (a)
	{
		if (a->top->content < mid)
		{
			pb(a, b);
			pb_count++;
		}
		else
			ra(a);
		if (pb_count == 2)
			break ;
	}
	a_sort_three(a);
	sort_two(a, b, B);
	pa(b, a);
	pa(b, a);
}
