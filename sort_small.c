/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:26:03 by selee             #+#    #+#             */
/*   Updated: 2021/08/12 17:40:15 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	mid;
	int	pb_count;

	mid = get_mid_nbr(stack_a->top, 4);
	pb_count = 0;
	while (stack_a)
	{
		if (stack_a->top->content < mid)
		{
			pb(stack_a, stack_b);
			pb_count++;
		}
		else
			ra(stack_a);
		if (pb_count == 1)
			break;
	}
	a_sort_three(stack_a);
	pa(stack_b, stack_a);
	if (stack_a->top->content > stack_a->top->next->content)
		sa(stack_a);
}

// big -> small

void	b_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	mid;
	int	pa_count;

	mid = get_mid_nbr(stack_b->top, 4);
	pa_count = 0;
	while (stack_b)
	{
		if (stack_b->top->content < mid)
		{
			pa(stack_b, stack_a);
			pa_count++;
		}
		else
			rb(stack_b);
		if (pa_count == 1)
			break;
	}
	b_sort_three(stack_b);
	pb(stack_a, stack_b);
	if (stack_b->top->content < stack_b->top->next->content)
		sb(stack_b);
}

void	sort_less_five(t_stack *stack_a, t_stack *stack_b, int count, int a_or_b)
{
	if (a_or_b == A)
	{
		if (count == 1)
			return ;
		else if (count == 2)
			sort_two(stack_a, stack_b, A);
		else if (count == 3)
			a_sort_three(stack_a);
		else if (count == 4)
			a_sort_four(stack_a, stack_b);
	}
	else if (a_or_b == B)
	{
		if (count == 1)
			return ;
		else if (count == 2)
			sort_two(stack_a, stack_b, B);
		else if (count == 3)
			b_sort_three(stack_b);
		else if (count == 4)
			b_sort_four(stack_a, stack_b);
	}
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	mid;
	int	pb_count;

	mid = get_mid_nbr(stack_a->top, stack_a->node_count);
	pb_count = 0;
	while (stack_a)
	{
		if (stack_a->top->content < mid)
		{
			pb(stack_a, stack_b);
			pb_count++;
		}
		else
			ra(stack_a);
		if (pb_count == 2)
			break;	
	}
	a_sort_three(stack_a);
	sort_two(stack_a, stack_b, B);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
