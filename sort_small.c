/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:26:03 by selee             #+#    #+#             */
/*   Updated: 2021/08/10 01:26:04 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_a(t_stack *stack_a)
{
	if (stack_a->top->content > stack_a->top->next->content)
		sa(stack_a);
}

void	sort_two_b(t_stack *stack_b)
{
	if (stack_b->top->content < stack_b->top->next->content)
		sb(stack_b);
}


//to be put inside push_swap function
void	sort_less_five(t_stack *stack_a, t_stack *stack_b)  
{
	if (stack_a)
	{
		if (stack_a->node_count == 1)
			return ;
		else if (stack_a->node_count == 2)
			sort_two_a(stack_a);
		else if (stack_a->node_count == 3)
			sort_three_args(stack_a);
		
	}
//arg is 4

}

