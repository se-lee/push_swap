/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_stack_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 23:47:56 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 16:57:52 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_reverse_b(t_push_swap *ps)
{
	if (ps->b.top->content < ps->b.top->next->content)
		op_swap_b(ps);
}

void	divide_stack_b(t_push_swap *ps, t_op_count *count, int *pivot)
{
	if (ps->b.top->content > *pivot)
	{
		op_push_to_a(ps);
		count->pa_count++;
	}
	else
	{
		op_rotate_b(ps);
		count->rb_count++;
	}
}

t_op_count	partition_b_in_range(t_push_swap *ps, int range)
{
	int			pivot;
	int			temp;
	t_op_count	count;

	pivot = find_mid_value_in_range_b(ps, &ps->b, range);
	init_op_count(&count);
	temp = range;
	while (temp--)
		divide_stack_b(ps, &count, &pivot);
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
