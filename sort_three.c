/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:26:27 by selee             #+#    #+#             */
/*   Updated: 2021/08/15 15:19:36 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_a(t_stack *a)
{
	if (a->top->content > a->top->next->content)
		op_swap_a(a);
}

void	sort_two_reverse_b(t_stack *b)
{
	if (b->top->content < b->top->next->content)
		op_swap_b(b);
}


void	sort_three_top_is_min(t_stack *stack_a)
{
	op_reverse_rotate_a(stack_a);
	op_swap_a(stack_a);
}

void	sort_three_top_is_mid(t_stack *stack_a)
{
	if (stack_a->top->next->content < stack_a->top->content)
		op_swap_a(stack_a);
	else if (stack_a->top->next->content > stack_a->top->content)
		op_reverse_rotate_a(stack_a);
}

void	sort_three_top_is_max(t_stack *stack_a)
{
	int	min;

	min = find_min_value_in_range(stack_a->top, 3);
	if (stack_a->top->next->content == min)
		op_rotate_a(stack_a);
	else if (stack_a->top->next->content != min)
	{
		op_rotate_a(stack_a);
		op_swap_a(stack_a);
	}
}

void	sort_three_a(t_stack *stack_a)
{
	int	min;
	int	mid;
	int	max;

	min = find_min_value_in_range(stack_a->top, 3);
	mid = find_mid_value_in_range(stack_a->top, 3);
	max = find_max_value_in_range(stack_a->top, 3);
	if (stack_a->top->content == min)
		sort_three_top_is_min(stack_a);
	else if (stack_a->top->content == mid)
		sort_three_top_is_mid(stack_a);
	else if (stack_a->top->content == max)
		sort_three_top_is_max(stack_a);
}

