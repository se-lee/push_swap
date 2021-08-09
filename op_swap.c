/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:59 by selee             #+#    #+#             */
/*   Updated: 2021/08/09 04:46:42 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	if (stack->node_count < 2)
		return ;
	if (stack->node_count > 2)
	{
		stack->top->next->next->prev = stack->top;
		stack->top->prev = stack->top->next;
		stack->top->next = stack->top->next->next;
		stack->top->prev->next = stack->top;
		stack->top = stack->top->prev;
		stack->top->prev = NULL;
	}
	else if (stack->node_count == 2)
	{
		stack->bottom = stack->top;
		stack->top->prev = stack->top->next;
		stack->top->next = stack->top->next->next; //should be NULL;
		stack->top->prev->next = stack->top;
		stack->top = stack->top->prev;
		stack->top->prev = NULL;
	}
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *stack)
{
	if (stack->node_count < 2)
		return ;
	if (stack->node_count > 2)
	{
		stack->top->next->next->prev = stack->top;
		stack->top->prev = stack->top->next;
		stack->top->next = stack->top->next->next;
		stack->top->prev->next = stack->top;
		stack->top = stack->top->prev;
		stack->top->prev = NULL;
	}
	else if (stack->node_count == 2)
	{
		stack->bottom = stack->top;
		stack->top->prev = stack->top->next;
		stack->top->next = stack->top->next->next; //should be NULL;
		stack->top->prev->next = stack->top;
		stack->top = stack->top->prev;
		stack->top->prev = NULL;
	}
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_putendl_fd("ss", 1);
}
