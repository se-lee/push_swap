/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:14 by selee             #+#    #+#             */
/*   Updated: 2021/08/12 01:54:38 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->top = NULL;
	stack_a->bottom = NULL;
	stack_a->node_count = 0;
	stack_b->top = NULL;
	stack_b->bottom = NULL;
	stack_b->node_count = 0;

}

/* push (add on top) */
void	add_to_stack(t_stack *stack, t_node *new_node)
{
	if (stack->top == NULL)
		stack->top = new_node;
	else
	{
		new_node->next = stack->top;
		stack->top->prev = new_node;
		stack->top = new_node;
	}
}

/* add to the back(bottom) */
void	add_to_stack_back(t_stack *stack, t_node *new_node)
{
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
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		add_to_stack_back(stack, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}

void	print_list(t_stack *stack, char a_or_b)
{
	t_node	*node;

	node = stack->top;
	printf("---------------------------\n\n");
	while (node)
	{
		printf("%d  \n", node->content);
		node = node->next;
	}
	printf("---%c---\n", a_or_b);
	printf("---------------------------\n");
}
