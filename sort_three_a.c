/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:10:19 by selee             #+#    #+#             */
/*   Updated: 2021/08/16 21:11:09 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_a_3_alone(t_stack *a)
{
	int first; 
	int second;
	int third;
	
	first = a->top->content;
	second = a->top->next->content;
	third = a->bottom->content;
	if (first < second)
	{
		if (first > third)
			op_reverse_rotate_a(a);
		else if (third < second)
		{
			op_reverse_rotate_a(a);
			op_swap_a(a);
		}
	}
	else
	{
		if (first < third)
			op_swap_a(a);
		else if (second < third)
			op_rotate_a(a);
		else
		{
			op_swap_a(a);
			op_reverse_rotate_a(a);
		}
	}
}

static void	sort_a_3_not_alone(t_stack *a)
{
	int first; 
	int second;
	int third;
	
	first = a->top->content;
	second = a->top->next->content;
	third = a->top->next->next->content;

	if (first < second)
	{
		if (first > third)
		{
			op_rotate_a(a);
			op_swap_a(a);
			op_reverse_rotate_a(a);
			op_swap_a(a);
		}
		else if (third < second)
		{
			op_rotate_a(a);
			op_swap_a(a);
			op_reverse_rotate_a(a);
		}
	}
	else
	{
		if (first < third)
			op_swap_a(a);
		else if (second < third)
		{
			op_swap_a(a);
			op_rotate_a(a);
			op_swap_a(a);
			op_reverse_rotate_a(a);
		}
		else
		{
			op_swap_a(a);
			op_rotate_a(a);
			op_swap_a(a);
			op_reverse_rotate_a(a);
			op_swap_a(a);
		}
	}
}

void sort_a_3(t_stack *a)
{
	if (a->node_count == 3)
		sort_a_3_alone(a);
	else
		sort_a_3_not_alone(a);
}

