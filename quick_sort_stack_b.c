/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_stack_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 23:47:56 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 03:14:18 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_reverse_b(t_push_swap *ps)
{
	if (ps->b.top->content < ps->b.top->next->content)
		op_swap_b(ps);
}

#include <assert.h>

t_op_count	partition_b_in_range(t_push_swap *ps, int range)
{
	int	pivot;
	int	temp;
	t_op_count count;

	pivot = find_mid_value_in_range_b(ps->b.top, range);
	init_op_count(&count);
	temp = range;
	while (temp--)
	{
		if (ps->b.top->content > pivot)
		{
			op_push_to_a(ps);
			count.pa_count++;
		}
		else
		{
			op_rotate_b(ps);
			count.rb_count++;
		}
	}
	// if (!(count.rb_count == count.pa_count + 1
	//	|| count.rb_count == count.pa_count))
	// {
	//	printf("%d %d", count.rb_count, count.pa_count);
	//	exit(1);
	//}
	if (count.rb_count != ps->b.node_count)
	{
		temp = count.rb_count;
		while (temp--)
			op_reverse_rotate_b(ps);
	}
	return (count);
}

void	quick_sort_b(t_push_swap *ps, int range)
{
	t_op_count	count;

	if (range <= 1 || stack_is_reverse_sorted(&ps->b))
		return ;
	if (range == 2)
		return (sort_two_reverse_b(ps));
	if (range == 3)
		return (sort_b_3(ps));
	count = partition_b_in_range(ps, range);
	quick_sort_b(ps, count.rb_count);
	quick_sort_a(ps, count.pa_count);
	while (count.pa_count--)
		op_push_to_b(ps);
}