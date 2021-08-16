/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:07:29 by selee             #+#    #+#             */
/*   Updated: 2021/08/16 23:13:58 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_last_node(t_stack *source, t_stack *dest)
{
	if (dest->top == NULL)
	{
		dest->top = source->top;
		dest->bottom = dest->top;
	}
	else
	{
		dest->top->prev = source->top;
		source->top->next = dest->top;
		dest->top = dest->top->prev;
	}
	source->top = NULL;
	source->bottom = NULL;
}

void	op_push_to_a(t_push_swap *ps)
{
	if (ps->b.top == NULL)
		return ;
	if (ps->b.node_count == 1)
		push_last_node(&ps->b, &ps->a);
	else
	{
		if (ps->a.top == NULL)
		{
			ps->a.top = ps->b.top;
			ps->a.bottom = ps->a.top;
			ps->b.top = ps->b.top->next;
			ps->b.top->prev = NULL;
			ps->a.top->next = NULL;
		}
		else
		{
			ps->a.top->prev = ps->b.top;
			ps->b.top = ps->b.top->next;
			ps->a.top->prev->next = ps->a.top;
			ps->a.top = ps->a.top->prev;
			ps->b.top->prev = NULL;
		}
	}
	ps->b.node_count--;
	ps->a.node_count++;
	program_add_instruction(&ps->program, pa);
}

void	op_push_to_b(t_push_swap *ps)
{
	if (ps->a.top == NULL)
		return ;
	if (ps->a.node_count == 1)
		push_last_node(&ps->a, &ps->b);
	else
	{
		if (ps->b.top == NULL)
		{
			ps->b.top = ps->a.top;
			ps->b.bottom = ps->b.top;
			ps->a.top = ps->a.top->next;
			ps->a.top->prev = NULL;
			ps->b.top->next = NULL;
		}
		else
		{
			ps->b.top->prev = ps->a.top;
			ps->a.top = ps->a.top->next;
			ps->b.top->prev->next = ps->b.top;
			ps->b.top = ps->b.top->prev;
			ps->a.top->prev = NULL;
		}
	}
	ps->a.node_count--;
	ps->b.node_count++;
	program_add_instruction(&ps->program, pb);
}
