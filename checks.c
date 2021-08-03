/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:33:03 by selee             #+#    #+#             */
/*   Updated: 2021/08/03 21:55:52 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_no_arg(int argc)
{
	if (argc <= 1)
		return (-1);
	else
		return (0);
}

int	check_non_int(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 1;

	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int check_sorted(t_stack *stack)
{
	t_node *cursor;

	cursor = stack->top;
	while (cursor->next != NULL)
	{
		if (cursor->content > cursor->next->content)
			return (-1);
		cursor = cursor->next;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int no_arg;
	int non_int;
	int dup;

	no_arg = check_no_arg(argc);
	non_int= check_non_int(argv);
	dup = check_duplicate(argv);

	printf("no_arg: %d\n", no_arg);
	printf("non_int: %d\n", no_arg);
	printf("dup: %d\n", no_arg);

	return (0);
}
