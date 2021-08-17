/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_optimize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 04:10:09 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 04:13:35 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	instruction_cancel_each_other(t_instruction a, t_instruction b)
{
	return ((a == pa && b == pb) || (a == pb && b == pa)
		|| (a == ra && b == rra) || (a == rra && b == ra)
		|| (a == rb && b == rrb) || (a == rrb && b == rb)
		|| (a == sa && b == sa) || (a == sb && b == sb));
}

static void	program_remove_useless(t_program *program)
{
	t_instruction	a;
	t_instruction	b;
	t_program_node	*cursor;
	t_program_node	*previous;
	t_program_node	*rest;

	cursor = program->first;
	while (cursor != NULL && cursor->next != NULL)
	{
		a = cursor->instruction;
		b = cursor->next->instruction;
		if (instruction_cancel_each_other(a, b))
		{
			previous = cursor->prev;
			rest = cursor->next->next;
			free(cursor->next);
			free(cursor);
			if (previous != NULL)
			{
				previous->next = rest;
				if (rest != NULL)
					rest->prev = previous;
				cursor = previous;
			}
			else
			{
				program->first = rest;
				cursor = program->first;
			}
		}
		else
			cursor = cursor->next;
	}
}

static int	try_merge_instructions(
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

static void	program_merge_instructions(t_program *program)
{
	t_instruction	a;
	t_instruction	b;
	t_instruction	result;
	t_program_node	*cursor;
	t_program_node	*to_free;

	cursor = program->first;
	while (cursor != NULL && cursor->next != NULL)
	{
		a = cursor->instruction;
		b = cursor->next->instruction;
		if (try_merge_instructions(a, b, &result))
		{
			if (cursor->prev)
				cursor->prev->next = cursor->next;
			else
				program->first = cursor->next;
			cursor->next->prev = cursor->prev;
			to_free = cursor;
			cursor = cursor->next;
			cursor->instruction = result;
			free(to_free);
		}
		else
			cursor = cursor->next;
	}
}

void	program_optimize(t_program *program)
{
	program_remove_useless(program);
	program_merge_instructions(program);
}
