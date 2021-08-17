/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:10:19 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 15:52:34 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a_3_alone_op(t_push_swap *ps, int first, int second, int third)
{
	if (first < second)
	{
		if (first > third)
			op_reverse_rotate_a(ps);
		else if (third < second)
		{
			op_reverse_rotate_a(ps);
			op_swap_a(ps);
		}
	}
	else
	{
		if (first < third)
			op_swap_a(ps);
		else if (second < third)
			op_rotate_a(ps);
		else
		{
			op_swap_a(ps);
			op_reverse_rotate_a(ps);
		}
	}
}

static void	sort_a_3_alone(t_push_swap *ps)
{
	int	first;
	int	second;
	int	third;

	first = ps->a.top->content;
	second = ps->a.top->next->content;
	third = ps->a.bottom->content;
	sort_a_3_alone_op(ps, first, second, third);
}

static void	sort_a_3_not_alone_op(t_push_swap *ps,
			int first, int second, int third)
{
	if (first < third)
		op_swap_a(ps);
	else if (second < third)
	{
		op_swap_a(ps);
		op_rotate_a(ps);
		op_swap_a(ps);
		op_reverse_rotate_a(ps);
	}
	else
	{
		op_swap_a(ps);
		op_rotate_a(ps);
		op_swap_a(ps);
		op_reverse_rotate_a(ps);
		op_swap_a(ps);
	}
}

static void	sort_a_3_not_alone(t_push_swap *ps)
{
	int	first;
	int	second;
	int	third;

	first = ps->a.top->content;
	second = ps->a.top->next->content;
	third = ps->a.top->next->next->content;
	if (first < second)
	{
		if (first > third)
		{
			op_rotate_a(ps);
			op_swap_a(ps);
			op_reverse_rotate_a(ps);
			op_swap_a(ps);
		}
		else if (third < second)
		{
			op_rotate_a(ps);
			op_swap_a(ps);
			op_reverse_rotate_a(ps);
		}
	}
	else
		sort_a_3_not_alone_op(ps, first, second, third);
}

void	sort_a_3(t_push_swap *ps)
{
	if (ps->a.node_count == 3)
		sort_a_3_alone(ps);
	else
		sort_a_3_not_alone(ps);
}
