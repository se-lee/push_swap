/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:26:05 by selee             #+#    #+#             */
/*   Updated: 2021/08/10 01:26:07 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
get mid number,
pb two numbers smaller than mid number,
in stack b, sort big->small
in stack a, do three number sort
pa two numbers
*/

void	sort_two_b(t_stack *stack)
{
	if (stack->top->content < stack->top->next->content)
		sb(stack);
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
	sort_three_args(stack_a);
	sort_two_b(stack_b);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
