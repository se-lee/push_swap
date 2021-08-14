/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:33:03 by selee             #+#    #+#             */
/*   Updated: 2021/08/14 20:09:05 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
• In case of error, you must display Error followed by a ’\n’ on the standard error.

Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer, and/or there are duplicates.

*/

void	check_non_int(char **argv) //display error
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
			{
				ft_putendl_fd("Error", 2);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

/*
--- need to check min/max int; display error

int max: +2147483647
int min: -2147483648

*/

void	check_duplicate(t_node *top) //display error
{
	int		value;
	t_node	*cursor;

	while (top->next != NULL)
	{
		cursor = top->next;
		value = top->content;
		while (cursor)
		{
			if (cursor->content == value)
			{
				ft_putendl_fd("Error", 2); // fd 2 is stderr
				exit(0);
			}
			if (cursor->next)
				cursor = cursor->next;
			else
				break;
		}
		top = top->next;
	}
}

//if already sorted, do nothing (no error message)
int	stack_is_sorted(t_stack *stack) // no error message
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

int	is_sorted_reverse(t_stack *stack)
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
