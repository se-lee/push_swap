/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:14 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 17:52:40 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->node_count = 0;
}

void	stack_add_node_back(t_stack *stack, t_node *node)
{
	if (stack->top == NULL)
		stack->top = node;
	else
		stack->bottom->next = node;
	node->prev = stack->bottom;
	stack->bottom = node;
	stack->node_count += 1;
}

void	stack_store_value(t_push_swap *ps, char **argv, t_stack *stack)
{
	int		i;
	t_node	*new_node;

	i = 1;
	while (argv[i])
	{
		new_node = ft_lstnew(ft_atoi(argv[i]));
		if (!new_node)
			print_error_exit(ps);
		stack_add_node_back(stack, new_node);
		i++;
	}
}

void	stack_free(t_stack *stack)
{
	t_node	*to_free;

	while (stack->top != NULL)
	{
		to_free = stack->top;
		stack->top = stack->top->next;
		free(to_free);
	}
	stack->node_count = 0;
	stack->bottom = 0;
}

void	stack_free_all(t_stack *a, t_stack *b)
{
	stack_free(a);
	stack_free(b);
}
