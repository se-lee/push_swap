/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:07:29 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 05:33:09 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_push_to_a(t_push_swap *ps)
{
	t_node	*node;

	if (ps->b.top == NULL)
		return ;
	node = ps->b.top;
	ps->b.top = ps->b.top->next;
	ps->b.node_count--;
	if (ps->b.top)
		ps->b.top->prev = NULL;
	else
		ps->b.bottom = NULL;
	node->next = ps->a.top;
	ps->a.top = node;
	if (ps->a.bottom == NULL)
		ps->a.bottom = node;
	ps->a.node_count++;
	program_add_instruction(&ps->program, pa);
}

void	op_push_to_b(t_push_swap *ps)
{
	t_node	*node;

	if (ps->a.top == NULL)
		return ;
	node = ps->a.top;
	ps->a.top = ps->a.top->next;
	ps->a.node_count--;
	if (ps->a.top)
		ps->a.top->prev = NULL;
	else
		ps->a.bottom = NULL;
	node->next = ps->b.top;
	ps->b.top = node;
	if (ps->b.bottom == NULL)
		ps->b.bottom = node;
	ps->b.node_count++;
	program_add_instruction(&ps->program, pb);
}
