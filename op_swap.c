/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:59 by selee             #+#    #+#             */
/*   Updated: 2021/08/07 02:26:48 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	stack->top->next->next->prev = stack->top;
	stack->top->prev = stack->top->next;
	stack->top->next = stack->top->next->next;
	stack->top->prev->next = stack->top;
	stack->top = stack->top->prev;
	stack->top->prev = NULL;
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *stack)
{
	stack->top->next->next->prev = stack->top;
	stack->top->prev = stack->top->next;
	stack->top->next = stack->top->next->next;
	stack->top->prev->next = stack->top;
	stack->top = stack->top->prev;
	stack->top->prev = NULL;
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_putendl_fd("ss", 1);
}

void pop_and_push(t_stack *source, t_stack *dest)
{//pop from stack1, push to stack2
	//t_node	top1;
	//t_node	top2;
	if (dest->top == NULL)
	{
		dest->top = source->top;
		source->top = source->top->next;
		source->top->prev = NULL;
		dest->top->next = NULL;
	}
	else
	{
		dest->top->prev = source->top;
		source->top = source->top->next;
		dest->top->prev->next = dest->top;
		dest->top = dest->top->prev;
		if (source->top->next == NULL)
			source->top = NULL;
		source->top->prev = NULL;
	}
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

/*
int main(int argc, char **argv)
{
	t_stack	stack_a;

	init_stack(&stack_a);
	store_to_stack(argv, &stack_a);
	printf("before:\n");
	print_list(&stack_a);

	swap(&stack_a);

	printf("after:\n");
	print_list(&stack_a);

	return (0);
}
*/