/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:27:07 by selee             #+#    #+#             */
/*   Updated: 2021/08/15 23:24:35 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->node_count < 5)
		sort_less_five(a, b, a->node_count);
	else if (a->node_count == 5)
		sort_five(a, b);
	else
		quick_sort_a(a, b, a->node_count);
 }
 