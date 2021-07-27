/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:14 by selee             #+#    #+#             */
/*   Updated: 2021/07/27 16:31:20 by selee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->node_count = 0;
}

void add_to_stack(t_stack *stack, t_node *new_node)
{//push (add on top)
	if (stack->top == NULL)
		stack->top = new_node;
	else
	{
		new_node->next = stack->top;
		stack->top->prev = new_node;
		stack->top = new_node;
	}
}

void add_to_stack_back(t_stack *stack, t_node *new_node)
{//add to the back(bottom)
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->bottom = new_node;
		stack->node_count++;
	}
	else
	{
		new_node->prev = stack->bottom;
		stack->bottom->next = new_node;
		new_node->prev = stack->bottom;
		stack->bottom = new_node;
		stack->node_count++;
	}
}

void	store_to_stack(char **argv, t_stack *stack)
{
	int i;
//	t_stack stack;

//	init_stack(&stack);
	i = 1;
	while (argv[i] != NULL)
	{
		add_to_stack_back(stack, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}

void	print_list(t_stack *stack)
{
	t_node *node;

	node = stack->top;
	printf("\n\n");
	while (node != NULL)
	{
		printf("%d \n", node->content);
		node = node->next;
	}
}

