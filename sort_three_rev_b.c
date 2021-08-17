/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_rev_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 00:04:45 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 04:20:46 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_b_3_alone(t_push_swap *ps)
{
	int	first;
	int	second;
	int	third;

	first = ps->b.top->content;
	second = ps->b.top->next->content;
	third = ps->b.bottom->content;
	if (first > second)
	{
		if (first < third)
			op_reverse_rotate_b(ps);
		else if (third > second)
		{
			op_reverse_rotate_b(ps);
			op_swap_b(ps);
		}
	}
	else
	{
		if (first > third)
			op_swap_b(ps);
		else if (second > third)
			op_rotate_b(ps);
		else
		{
			op_swap_b(ps);
			op_reverse_rotate_b(ps);
		}
	}
}

static void	sort_b_3_not_alone(t_push_swap *ps)
{
	int	first;
	int	second;
	int	third;

	first = ps->b.top->content;
	second = ps->b.top->next->content;
	third = ps->b.top->next->next->content;
	if (first > second)
	{
		if (first < third)
		{
			op_rotate_b(ps);
			op_swap_b(ps);
			op_reverse_rotate_b(ps);
			op_swap_b(ps);
		}
		else if (third > second)
		{
			op_rotate_b(ps);
			op_swap_b(ps);
			op_reverse_rotate_b(ps);
		}
	}
	else
	{
		if (first > third)
			op_swap_b(ps);
		else if (second > third)
		{
			op_swap_b(ps);
			op_rotate_b(ps);
			op_swap_b(ps);
			op_reverse_rotate_b(ps);
		}
		else
		{
			op_swap_b(ps);
			op_rotate_b(ps);
			op_swap_b(ps);
			op_reverse_rotate_b(ps);
			op_swap_b(ps);
		}
	}
}

void	sort_b_3(t_push_swap *ps)
{
	if (ps->b.node_count == 3)
		sort_b_3_alone(ps);
	else
		sort_b_3_not_alone(ps);
}
