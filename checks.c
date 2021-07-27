/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:33:03 by selee             #+#    #+#             */
/*   Updated: 2021/07/27 17:05:21 by selee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*check*/
//whether arguments are valid: strings, decimals, no argument, ...what else?
//whether stack arguments are already sorted -> do nothing

int check_sorted(t_stack *stack)
{//if stack is sorted, return 0; if not sorted return -1;
	t_node *cursor;

	cursor = stack->top;
	while (cursor->next != NULL)
	{
		if (cursor->content < cursor->next->content)
			cursor = cursor->next;
		else
			return (-1);
	}
	return (0);
}

int	check_no_arg(int argc)
{// if there is no argument return -1;
	if (argc <= 1)
		return (-1);
	else
		return (0);
}

int	check_non_int(char *arg)
{//check if argument includes non-int values
	int	i;

	i = 0;
	while (arg[i] != NULL)
	{
		if ()
/*
int	ft_isalpha(int c)
int	ft_isascii(int c)
int	ft_isdigit(int c)
...
*/
	}
}

int	check_duplicate();
// if duplicate number is found, return -1;

int check_int_max_min();
//check if the argument is bigger/smaller than int max/min

