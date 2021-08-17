/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:27:07 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 03:27:15 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_solve(t_push_swap *ps)
{
	quick_sort_a(ps, ps->a.node_count);
	program_optimize(&ps->program);
	program_run(&ps->program);
}
 
