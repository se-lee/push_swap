/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:27:07 by selee             #+#    #+#             */
/*   Updated: 2021/08/14 13:49:23 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->node_count < 5)
		sort_less_five(a, b, a->node_count, A);
	else if (a->node_count == 5)
		sort_five(a, b);
	else
		sort_a(a, b, a->node_count);
 } 
 