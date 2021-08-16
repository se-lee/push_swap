/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_upto_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:26:03 by selee             #+#    #+#             */
/*   Updated: 2021/08/16 16:40:12 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four_a(t_stack *a, t_stack *b)
{
	int	mid;
	int	pb_count;

	mid = find_mid_value_in_range(a->top, 4);
	pb_count = 0;
	while (a)
	{
		if (a->top->content < mid)
		{
			op_push_to_b(a, b);
			pb_count++;
		}
		else
			op_rotate_a(a);
		if (pb_count == 1)
			break ;
	}
	sort_three_a(a);
	op_push_to_a(b, a);
	if (a->top->content > a->top->next->content)
		op_swap_a(a);
}

void	sort_less_five_a(t_stack *a, t_stack *b, int count)
{
	(void)b;
	if (count == 1)
		return ;
	else if (count == 2)
		sort_two_a(a);
	else if (count == 3)
		sort_three_a(a);
	// else if (count == 4)
	//	sort_four_a(a, b);
}

// void	sort_less_five_a(t_stack *a, t_stack *b, int count, int a_b)
// {
// 	if (a_b == A)
// 	{
// 		if (count == 1)
// 			return ;
// 		else if (count == 2)
// 			sort_two_a(a);
// 		else if (count == 3)
// 			sort_three_a(a);
// 		else if (count == 4)
// 			sort_four_a(a, b);
// 	}
// 	else if (a_b == B)
// 	{
// 		if (count == 1)
// 			return ;
// 		else if (count == 2)
// 			sort_two_reverse_b(b);
// 		else if (count == 3)
// 			sort_three_reverse_b(b);
// 		else if (count == 4)
// 			sort_four_reverse_b(a, b);
// //		push_back_a(a, b, count);
// 	}
// }

void	sort_five(t_stack *a, t_stack *b)
{
	int	mid;
	int	pb_count;

	mid = find_mid_value_in_range(a->top, a->node_count);
	pb_count = 0;
	while (a)
	{
		if (a->top->content < mid)
		{
			op_push_to_b(a, b);
			pb_count++;
		}
		else
			op_rotate_a(a);
		if (pb_count == 2)
			break ;
	}
	sort_three_a(a);
	sort_two_reverse_b(b);
	push_back_a(a, b, 2);
}
