/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:26:03 by selee             #+#    #+#             */
/*   Updated: 2021/08/11 07:45:15 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort_two_a(t_stack *stack_a)
// {
// 	if (stack_a->top->content > stack_a->top->next->content)
// 		sa(stack_a);
// }
// void	sort_two_b(t_stack *stack_b)
// {
// 	if (stack_b->top->content < stack_b->top->next->content)
// 		sb(stack_b);
		
// }

void	sort_two(t_stack *stack_a, t_stack *stack_b, int a_or_b)
{
	if (a_or_b == A)
	{
		if (stack_a->top->content > stack_a->top->next->content)
			sa(stack_a);
	}
	else if (a_or_b == B)
	{
		if (stack_b->top->content < stack_b->top->next->content)
			sb(stack_b);
	}
}

//to be put inside push_swap function -> あとでこれ消す
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
//stack_aを3にしてソートする。 ＝＝bに一個だけ送る。AがソートできたらｂからAに戻す
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	mid;
	int	pb_count;

	mid = get_mid_nbr(stack_a->top, 4);
	pb_count = 0;
	while (stack_a)
	{
		if (stack_b->top->content < mid)
		{
			pb(stack_a, stack_b);
			pb_count++;
		}
		else
			ra(stack_a);
		if (pb_count == 1)
			break;
	}
	sort_three_args(stack_a);
	pa(stack_b, stack_a);
	if (stack_a->top->content > stack_a->top->next->content)
		sa(stack_a);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b, int a_or_b)
{
	int min;

	min = get_min_nbr(stack_a);
	if (a_or_b == A)
	{
		if (stack_a->node_count == 1)
			return ;
		else if (stack_a->node_count == 2)
			sort_two(stack_a, stack_b, A);
		else if (stack_a->node_count == 3)
			sort_three_args(stack_a);
		else if (stack_a->node_count == 4)
			sort_four(stack_a, stack_b);
	}
	else if (a_or_b == B)
	{
		if (stack_b->node_count == 1)
			return ;
		else if (stack_b->node_count == 2)
			sort_two(stack_a, stack_b, B);
		else if (stack_b->node_count == 3)
			b_sort_three(stack_b);
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
	sort_three_args(stack_a);
	sort_two(stack_a, stack_b, B);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
