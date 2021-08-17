/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 04:11:24 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 04:12:13 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*g_instruction_names[12] = {
	"pa", "pb",
	"ra", "rb", "rr",
	"sa", "sb", "ss",
	"rra", "rrb", "rrr",
};

void	program_init(t_program *program)
{
	program->first = NULL;
	program->last = NULL;
}

void	program_add_instruction(t_program *program, t_instruction instruction)
{
	t_program_node	*node;

	node = malloc(sizeof(t_program_node));
	node->instruction = instruction;
	node->next = NULL;
	if (program->first == NULL)
		program->first = node;
	else
		program->last->next = node;
	node->prev = program->last;
	program->last = node;
}

void	program_run(t_program *program)
{
	t_program_node	*cursor;

	cursor = program->first;
	while (cursor != NULL)
	{
		ft_putendl_fd(g_instruction_names[cursor->instruction], 1);
		cursor = cursor->next;
	}
}

void	program_free(t_program *program)
{
	t_program_node	*cursor;
	t_program_node	*to_free;

	cursor = program->first;
	while (cursor != NULL)
	{
		to_free = cursor;
		cursor = cursor->next;
		free(to_free);
	}
}
