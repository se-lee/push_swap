/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:26:27 by selee             #+#    #+#             */
/*   Updated: 2021/08/14 12:35:04 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a, t_stack *b, int a_or_b)
{
	if (a_or_b == A)
	{
		if (a->top->content > a->top->next->content)
			sa(a);
	}
	else if (a_or_b == B)
	{
		if (b->top->content < b->top->next->content)
			sb(b);
	}
}

void	a_three_top_min(t_stack *stack_a)
{
	rra(stack_a);
	sa(stack_a);
}

void	a_three_top_mid(t_stack *stack_a)
{
	if (stack_a->top->next->content < stack_a->top->content)
		sa(stack_a);
	else if (stack_a->top->next->content > stack_a->top->content)
		rra(stack_a);
}

void	a_three_top_max(t_stack *stack_a)
{
	int	min;

	min = get_min_nbr(stack_a);
	if (stack_a->top->next->content == min)
		ra(stack_a);
	else if (stack_a->top->next->content != min)
	{
		ra(stack_a);
		sa(stack_a);
	}
}

void	a_sort_three(t_stack *stack_a)
{
	int	min;
	int	mid;
	int	max;

	min = get_min_nbr(stack_a);
	mid = get_mid_nbr(stack_a->top, 3);
	max = get_max_nbr(stack_a);
	if (stack_a->top->content == min)
		a_three_top_min(stack_a);
	else if (stack_a->top->content == mid)
		a_three_top_mid(stack_a);
	else if (stack_a->top->content == max)
		a_three_top_max(stack_a);
}

