/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:59 by selee             #+#    #+#             */
/*   Updated: 2021/08/16 21:57:05 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_swap_a(t_stack *stack)
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
		stack->top->next = stack->top->next->next;
		stack->top->prev->next = stack->top;
		stack->top = stack->top->prev;
		stack->top->prev = NULL;
	}
	ft_putendl_fd("sa", 1);
}

void	op_swap_b(t_stack *stack)
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
		stack->top->next = stack->top->next->next;
		stack->top->prev->next = stack->top;
		stack->top = stack->top->prev;
		stack->top->prev = NULL;
	}
	ft_putendl_fd("sb", 1);
}

void	op_swap_all(t_stack *stack_a, t_stack *stack_b)
{
	op_swap_a(stack_a);
	op_swap_b(stack_b);
	ft_putendl_fd("ss", 1);
}
