/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_optimize2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:12:07 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 17:57:03 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	program_remove_useless2(t_program **program,
	t_program_node **previous, t_program_node **rest, t_program_node **cursor)
{
	(*previous) = (*cursor)->prev;
	(*rest) = (*cursor)->next->next;
	free((*cursor)->next);
	free(*cursor);
	if (*previous != NULL)
	{
		(*previous)->next = (*rest);
		if (*rest != NULL)
			(*rest)->prev = (*previous);
		*cursor = *previous;
	}
	else
	{
		(*program)->first = *rest;
		*cursor = (*program)->first;
	}
}

static void	program_remove_useless(t_program *program)
{
	t_instruction	a;
	t_instruction	b;
	t_program_node	*cursor;
	t_program_node	*previous;
	t_program_node	*rest;

	cursor = program->first;
	previous = NULL;
	rest = NULL;
	while (cursor != NULL && cursor->next != NULL)
	{
		a = cursor->instruction;
		b = cursor->next->instruction;
		if (instruction_cancel_each_other(a, b))
		{
			program_remove_useless2(&program, &previous, &rest, &cursor);
		}
		else
			cursor = cursor->next;
	}
}

static void	program_merge_instructions2(t_program *program, \
	t_program_node	*cursor, t_program_node	*to_free, t_instruction *result)
{
	if (cursor->prev)
		cursor->prev->next = cursor->next;
	else
		program->first = cursor->next;
	cursor->next->prev = cursor->prev;
	to_free = cursor;
	cursor = cursor->next;
	cursor->instruction = *result;
	free(to_free);
}

static void	program_merge_instructions(t_program *program)
{
	t_instruction	a;
	t_instruction	b;
	t_instruction	result;
	t_program_node	*cursor;
	t_program_node	*to_free;

	cursor = program->first;
	to_free = NULL;
	while (cursor != NULL && cursor->next != NULL)
	{
		a = cursor->instruction;
		b = cursor->next->instruction;
		if (try_merge_instructions(a, b, &result))
		{
			program_merge_instructions2(program, cursor, to_free, &result);
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
