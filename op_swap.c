/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:59 by selee             #+#    #+#             */
/*   Updated: 2021/08/16 23:10:05 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_swap_a_no_edit(t_push_swap *ps)
{
	if (ps->a.node_count < 2)
		return ;
	if (ps->a.node_count > 2)
	{
		ps->a.top->prev = ps->a.top->next;
		ps->a.top->next->next->prev = ps->a.top;
		ps->a.top->next = ps->a.top->next->next;
		ps->a.top->prev->next = ps->a.top;
		ps->a.top = ps->a.top->prev;
		ps->a.top->prev = NULL;
	}
	else if (ps->a.node_count == 2)
	{
		ps->a.bottom = ps->a.top;
		ps->a.top->prev = ps->a.top->next;
		ps->a.top->next = ps->a.top->next->next;
		ps->a.top->prev->next = ps->a.top;
		ps->a.top = ps->a.top->prev;
		ps->a.top->prev = NULL;
	}
}

void	op_swap_a(t_push_swap *ps)
{
	op_swap_a_no_edit(ps);
	program_add_instruction(&ps->program, sa);
}

static void	op_swap_b_no_edit(t_push_swap *ps)
{
	if (ps->b.node_count < 2)
		return ;
	if (ps->b.node_count > 2)
	{
		ps->b.top->next->next->prev = ps->b.top;
		ps->b.top->prev = ps->b.top->next;
		ps->b.top->next = ps->b.top->next->next;
		ps->b.top->prev->next = ps->b.top;
		ps->b.top = ps->b.top->prev;
		ps->b.top->prev = NULL;
	}
	else if (ps->b.node_count == 2)
	{
		ps->b.bottom = ps->b.top;
		ps->b.top->prev = ps->b.top->next;
		ps->b.top->next = ps->b.top->next->next;
		ps->b.top->prev->next = ps->b.top;
		ps->b.top = ps->b.top->prev;
		ps->b.top->prev = NULL;
	}
}

void	op_swap_b(t_push_swap *ps)
{
	op_swap_b_no_edit(ps);
	program_add_instruction(&ps->program, sb);
}

void	op_swap_all(t_push_swap *ps)
{
	op_swap_a_no_edit(ps);
	op_swap_b_no_edit(ps);
	program_add_instruction(&ps->program, ss);
}