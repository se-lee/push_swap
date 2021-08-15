/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:27:07 by selee             #+#    #+#             */
/*   Updated: 2021/08/16 00:10:03 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
//printf("mid: %d", find_mid_value_in_range(a->top, a->node_count));
	if (a->node_count < 5)
		sort_less_five(a, b, a->node_count);
	else if (a->node_count == 5)
		sort_five(a, b);
	else
		quick_sort_a(a, b, a->node_count);
 }
 