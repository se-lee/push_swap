/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:59 by selee             #+#    #+#             */
/*   Updated: 2021/08/04 01:13:10 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack *stack, t_node *node1, t_node *node2)
{
	t_node *temp;

	node1->prev = node2;
	node1->next = node2->next;
	node2->prev = NULL;
	node2->next = node1;
	node2->next->prev = node1;
	stack->top = node2;
}

void pop_and_push(t_stack *stack1, t_stack *stack2)
{//pop from stack1, push to stack2
	//t_node	top1;
	//t_node	top2;
	if (stack2->top == NULL)
	{
		stack2->top = stack1->top;
		stack1->top = stack1->top->next;
		stack1->top->prev = NULL;
		stack2->top->next = NULL;
	}
	else
	{
		stack2->top->prev = stack1->top;
		stack1->top = stack1->top->next;
		stack2->top->prev->next = stack2->top;
		stack2->top = stack2->top->prev;
		if (stack1->top->next == NULL)
			stack1->top = NULL;
		stack1->top->prev = NULL;
	}
}

//stack->top becomes bottom; stack->top->next becomes new stack->top;
void rotate(t_stack *stack)
{
	stack->top->prev = stack->bottom;
	stack->bottom->next = stack->top;
	stack->top->next->prev = NULL;
	stack->bottom = stack->top;
	stack->top = stack->bottom->next;
	stack->bottom->next = NULL;
}

//stack->bottom beomes top; stack->top becomes second node;
void rev_rotate(t_stack *stack)
{
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->top = stack->bottom;
	stack->bottom = stack->top->prev;
	stack->bottom->next = NULL;
	stack->top->prev = NULL;
}
