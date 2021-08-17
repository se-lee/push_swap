/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_rev_b_not_alone.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:32:40 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 15:47:48 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_b_3_not_alone_swap1(t_push_swap *ps,
		int first, int second, int third)
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

static void	sort_b_3_not_alone_swap2(t_push_swap *ps,
		int first, int second, int third)
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

void	sort_b_3_not_alone(t_push_swap *ps)
{
	int	first;
	int	second;
	int	third;

	first = ps->b.top->content;
	second = ps->b.top->next->content;
	third = ps->b.top->next->next->content;
	if (first > second)
		sort_b_3_not_alone_swap1(ps, first, second, third);
	else
		sort_b_3_not_alone_swap2(ps, first, second, third);
}
