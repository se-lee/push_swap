/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:59 by selee             #+#    #+#             */
/*   Updated: 2021/08/06 23:29:51 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack* stack)
{
	// t_node	*temp;
	
	// temp = stack->top;
	// temp->next = stack->top->next->next;
	stack->top->next->next->prev = stack->top;
	stack->top->prev = stack->top->next;
	stack->top->next = stack->top->prev->next;
	stack->top->prev->next = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
//	temp->prev = stack->top;
}

	// if (stack->size > 2)
	// 	top_next->next->prev = stack->top;
	// temp->next = top_next->next;
	// stack->top = top_next;
	// stack->top->prev = NULL;
	// stack->top->next = temp;
	// temp->prev = stack->top;
	// if (stack->size == 2)
	// 	stack->bottom = stack->top->next;
	// if (flag == A)

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

// stack a and b

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
