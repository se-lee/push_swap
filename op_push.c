/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:07:29 by selee             #+#    #+#             */
/*   Updated: 2021/08/16 14:21:26 by selee            ###   ########lyon.fr   */
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

void	op_push_to_a(t_stack *stack_b, t_stack *stack_a)
{
	if (stack_b->top == NULL)
		return ;
	if (stack_b->node_count == 1)
		push_last_node(stack_b, stack_a);
	else
	{
		if (stack_a->top == NULL)
		{
			stack_a->top = stack_b->top;
			stack_a->bottom = stack_a->top;
			stack_b->top = stack_b->top->next;
			stack_b->top->prev = NULL;
			stack_a->top->next = NULL;
		}
		else
		{
			stack_a->top->prev = stack_b->top;
			stack_b->top = stack_b->top->next;
			stack_a->top->prev->next = stack_a->top;
			stack_a->top = stack_a->top->prev;
			stack_b->top->prev = NULL;
		}
	}
	stack_b->node_count--;
	stack_a->node_count++;
	ft_putendl_fd("pa", 1);
}

void	op_push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top == NULL)
		return ;
	if (stack_a->node_count == 1)
		push_last_node(stack_a, stack_b);
	else
	{
		if (stack_b->top == NULL)
		{
			stack_b->top = stack_a->top;
			stack_b->bottom = stack_b->top;
			stack_a->top = stack_a->top->next;
			stack_a->top->prev = NULL;
			stack_b->top->next = NULL;
		}
		else
		{
			stack_b->top->prev = stack_a->top;
			stack_a->top = stack_a->top->next;
			stack_b->top->prev->next = stack_b->top;
			stack_b->top = stack_b->top->prev;
			stack_a->top->prev = NULL;
		}
	}
	stack_a->node_count--;
	stack_b->node_count++;
	ft_putendl_fd("pb", 1);
}
