/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:13:06 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 16:56:17 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_reverse_rotate_a_no_edit(t_push_swap *ps)
{
	ps->a.bottom->next = ps->a.top;
	ps->a.top->prev = ps->a.bottom;
	ps->a.top = ps->a.bottom;
	ps->a.bottom = ps->a.top->prev;
	if (ps->a.bottom != NULL)
		ps->a.bottom->next = NULL;
	ps->a.top->prev = NULL;
}

void	op_reverse_rotate_a(t_push_swap *ps)
{
	op_reverse_rotate_a_no_edit(ps);
	program_add_instruction(ps, &ps->program, rra);
}

void	op_reverse_rotate_b_no_edit(t_push_swap *ps)
{
	ps->b.bottom->next = ps->b.top;
	ps->b.top->prev = ps->b.bottom;
	ps->b.top = ps->b.bottom;
	ps->b.bottom = ps->b.top->prev;
	if (ps->b.bottom != NULL)
		ps->b.bottom->next = NULL;
	ps->b.top->prev = NULL;
}

void	op_reverse_rotate_b(t_push_swap *ps)
{
	op_reverse_rotate_b_no_edit(ps);
	program_add_instruction(ps, &ps->program, rrb);
}

void	op_reverse_rotate_all(t_push_swap *ps)
{
	op_reverse_rotate_a_no_edit(ps);
	op_reverse_rotate_b_no_edit(ps);
	program_add_instruction(ps, &ps->program, rrr);
}
