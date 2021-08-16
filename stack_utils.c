/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:14 by selee             #+#    #+#             */
/*   Updated: 2021/08/16 23:43:10 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->node_count = 0;
}

void	stack_add_node_back(t_stack *stack, t_node *new_node)
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

void	stack_store_value(char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		stack_add_node_back(stack, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}

void	stack_free(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->node_count)
	{
		free(stack->top);
		stack->top = stack->top->next;
		i++;
	}
	free(stack);
}

void	stack_free_all(t_stack *a, t_stack *b)
{
	stack_free(a);
	stack_free(b);
}
