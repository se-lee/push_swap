/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:13:06 by selee             #+#    #+#             */
/*   Updated: 2021/08/15 12:34:58 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_reverse_rotate_a(t_stack *stack)
{
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->top = stack->bottom;
	stack->bottom = stack->top->prev;
	stack->bottom->next = NULL;
	stack->top->prev = NULL;
	ft_putendl_fd("rra", 1);
}

void	op_reverse_rotate_b(t_stack *stack)
{
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->top = stack->bottom;
	stack->bottom = stack->top->prev;
	stack->bottom->next = NULL;
	stack->top->prev = NULL;
	ft_putendl_fd("rrb", 1);
}

void	op_reverse_rotate_all(t_stack *stack_a, t_stack *stack_b)
{
	op_reverse_rotate_a(stack_a);
	op_reverse_rotate_b(stack_b);
	ft_putendl_fd("rrr", 1);
}
