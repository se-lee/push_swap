/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:13:34 by selee             #+#    #+#             */
/*   Updated: 2021/08/16 23:17:50 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rotate_a_no_edit(t_push_swap *ps)
{
	ps->a.top->prev = ps->a.bottom;
	ps->a.bottom->next = ps->a.top;
	ps->a.top->next->prev = NULL;
	ps->a.bottom = ps->a.top;
	ps->a.top = ps->a.bottom->next;
	ps->a.bottom->next = NULL;
}

void	op_rotate_a(t_push_swap *ps)
{
	op_rotate_a_no_edit(ps);
	program_add_instruction(&ps->program, ra);
}

void	op_rotate_b_no_edit(t_push_swap *ps)
{
	ps->b.top->prev = ps->b.bottom;
	ps->b.bottom->next = ps->b.top;
	ps->b.top->next->prev = NULL;
	ps->b.bottom = ps->b.top;
	ps->b.top = ps->b.bottom->next;
	ps->b.bottom->next = NULL;
}

void	op_rotate_b(t_push_swap *ps)
{
	program_add_instruction(&ps->program, ra);
}

void	op_rotate_all(t_push_swap *ps)
{
	op_rotate_a_no_edit(ps);
	op_rotate_b_no_edit(ps);
	program_add_instruction(&ps->program, rr);
}
