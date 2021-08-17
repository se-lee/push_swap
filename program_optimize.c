/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_optimize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 04:10:09 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 15:19:50 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	instruction_cancel_each_other(t_instruction a, t_instruction b)
{
	return ((a == pa && b == pb) || (a == pb && b == pa)
		|| (a == ra && b == rra) || (a == rra && b == ra)
		|| (a == rb && b == rrb) || (a == rrb && b == rb)
		|| (a == sa && b == sa) || (a == sb && b == sb));
}

int	try_merge_instructions(
	t_instruction a,
	t_instruction b,
	t_instruction *result)
{
	if ((a == sa && b == sb) || (a == sb && b == sa))
		*result = ss;
	else if ((a == ra && b == rb) || (a == rb && b == ra))
		*result = rr;
	else if ((a == rra && b == rrb) || (a == rrb && b == rra))
		*result = rrr;
	else
		return (0);
	return (1);
}
