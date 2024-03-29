/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:13:34 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 16:56:28 by selee            ###   ########lyon.fr   */
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
	program_add_instruction(ps, &ps->program, ra);
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
	op_rotate_b_no_edit(ps);
	program_add_instruction(ps, &ps->program, rb);
}

void	op_rotate_all(t_push_swap *ps)
{
	op_rotate_a_no_edit(ps);
	op_rotate_b_no_edit(ps);
	program_add_instruction(ps, &ps->program, rr);
}
