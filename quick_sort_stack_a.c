/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 23:47:39 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 00:14:58 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op_count	partition_a_in_range(t_push_swap *ps, int range)
{
	int	pivot;
	int	temp;
	t_op_count	count;

	pivot = find_mid_value_in_range(ps->a.top, range);
	init_op_count(&count);
	temp = range;
	while (temp--)
	{
		if (ps->a.top->content <= pivot)
		{
			op_push_to_b(ps);
			count.pb_count++;
		}
		else
		{
			op_rotate_a(ps);
			count.ra_count++;
		}
	}

	if (count.ra_count != ps->a.node_count)
	{
		temp = count.ra_count;
		while (temp--)
			op_reverse_rotate_a(ps);
	}
	return (count);
}

void	quick_sort_a(t_push_swap *ps, int range)
{
	t_op_count count;

	if (range <= 1 || stack_is_sorted(&ps->a))
		return ;
	if (range == 2)
		return (sort_two_a(ps));
	if (range == 3)
		return (sort_a_3(ps));
	count = partition_a_in_range(ps, range);
	quick_sort_a(ps, count.ra_count);
	quick_sort_b(ps, count.pb_count);
	while (count.pb_count--)
		op_push_to_a(ps);
}
