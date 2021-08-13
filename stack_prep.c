/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:14 by selee             #+#    #+#             */
/*   Updated: 2021/08/13 16:06:04 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_op_count(t_pivcount *count)
{
	count->pa = 0;
	count->pb = 0;
	count->ra = 0;
	count->rb = 0;
}

void	init_stack(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->top = NULL;
	stack_a->bottom = NULL;
	stack_a->node_count = 0;
	stack_b->top = NULL;
	stack_b->bottom = NULL;
	stack_b->node_count = 0;
}

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

void	print_list(t_stack *stack, char a_b)
{
	t_node	*node;

	node = stack->top;
	printf("---------------------------\n\n");
	while (node)
	{
		printf("%d  \n", node->content);
		node = node->next;
	}
	printf("---%c---\n", a_b);
	printf("---------------------------\n");

}
