/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:33:03 by selee             #+#    #+#             */
/*   Updated: 2021/08/15 15:26:13 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
• In case of error, you must display Error followed by a ’\n’ on the standard error.

Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer, and/or there are duplicates.

*/

int		arg_is_int(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		if (argv[i][0] == '+' || argv[i][0] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
--- need to check min/max int; display error

int max: +2147483647
int min: -2147483648

*/

int		stack_has_duplicate(t_stack *stack)
{
	int	value;
	t_node	*cursor;

	while (stack)
	{
		cursor = stack->top->next;
		value = stack->top->content;
		while (cursor)
		{
			if (cursor->content == value)
				return (1);
			if (cursor->next)
				cursor = cursor->next;
			else
				break;
		}
		stack->top = stack->top->next;
	}
	return (0);
}

//if already sorted, do nothing (no error message)
int	stack_is_sorted(t_stack *stack)
{
	t_node	*cursor;

	cursor = stack->top;
	while (cursor->next != NULL)
	{
		if (cursor->content > cursor->next->content)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}

int	stack_is_reverse_sorted(t_stack *stack)
{
	t_node *cursor;

	cursor = stack->top;
	while (cursor->next != NULL)
	{
		if (cursor->content < cursor->next->content)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}
