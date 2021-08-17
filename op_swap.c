/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:59 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 17:42:33 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_swap_a_no_edit(t_push_swap *ps)
{
	t_node	*first;
	t_node	*second;
	t_node	*rest;

	if (ps->a.node_count < 2)
		return ;
	first = ps->a.top;
	second = first->next;
	rest = second->next;
	ps->a.top = second;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = rest;
	if (rest != NULL)
		rest->prev = first;
}

void	op_swap_a(t_push_swap *ps)
{
	op_swap_a_no_edit(ps);
	program_add_instruction(ps, &ps->program, sa);
}

static void	op_swap_b_no_edit(t_push_swap *ps)
{
	t_node	*first;
	t_node	*second;
	t_node	*rest;

	if (ps->a.node_count < 2)
		return ;
	first = ps->b.top;
	second = first->next;
	rest = second->next;
	ps->b.top = second;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = rest;
	if (rest != NULL)
		rest->prev = first;
}

void	op_swap_b(t_push_swap *ps)
{
	op_swap_b_no_edit(ps);
	program_add_instruction(ps, &ps->program, sb);
}

void	op_swap_all(t_push_swap *ps)
{
	op_swap_a_no_edit(ps);
	op_swap_b_no_edit(ps);
	program_add_instruction(ps, &ps->program, ss);
}
