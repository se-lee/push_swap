/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:14 by selee             #+#    #+#             */
/*   Updated: 2021/08/15 18:59:16 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_op_count(t_pivcount *count)
{
	count->pa_count = 0;
	count->pb_count = 0;
	count->ra_count = 0;
	count->rb_count = 0;
}

// t_stack *stack_init(void)
// {
// 	t_stack	*stack;

// 	stack = (t_stack *)malloc(sizeof(t_stack));
// 	if (!stack)
// 		return (NULL);
// 	stack->top = NULL;
// 	stack->bottom = NULL;
// 	stack->node_count = 0;

// 	return (stack);
// }


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
	while (argv[i] != NULL)
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
