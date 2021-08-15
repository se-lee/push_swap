/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_upto_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:26:27 by selee             #+#    #+#             */
/*   Updated: 2021/08/16 00:10:07 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_a(t_stack *a)
{
	if (a->top->content > a->top->next->content)
		op_swap_a(a);
}

void	sort_three_top_is_min(t_stack *a)
{
	if (!stack_is_sorted(a))
	{
		op_reverse_rotate_a(a);
		op_swap_a(a);
	}
}

void	sort_three_top_is_mid(t_stack *a)
{
	if (a->top->next->content < a->top->content)
		op_swap_a(a);
	else if (a->top->next->content > a->top->content)
		op_reverse_rotate_a(a);
}

void	sort_three_top_is_max(t_stack *a)
{
	int	min;

	min = find_min_value_in_range(a->top, 3);
	if (a->top->next->content == min)
		op_rotate_a(a);
	else if (a->top->next->content != min)
	{
		op_rotate_a(a);
		op_swap_a(a);
	}
}

void	sort_three_a(t_stack *a)
{
	int	min;
	int	mid;
	int	max;

	min = find_min_value_in_range(a->top, 3);
	mid = find_mid_value_in_range(a->top, 3);
	max = find_max_value_in_range(a->top, 3);
	if (a->top->content == min)
		sort_three_top_is_min(a);
	else if (a->top->content == mid)
		sort_three_top_is_mid(a);
	else if (a->top->content == max)
		sort_three_top_is_max(a);
}
