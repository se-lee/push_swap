/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:33:03 by selee             #+#    #+#             */
/*   Updated: 2021/08/13 13:30:45 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_non_int(char **argv)
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
			if (ft_isdigit(argv[i][j]) != 1)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

// once all arguments are digits, store as linked list

/*
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
*/

int	check_duplicate(t_node *top)
{
	int		value;
	t_node	*cursor;

	while (top->next != NULL)
	{
		cursor = top->next;
		value = top->content;
		while (cursor->next != NULL)
		{
			if (cursor->content == value)
				return (-1);
			cursor = cursor->next;
		}
		top = top->next;
	}
	return (0);
}

	// while (a->next)
	// {
	// 	temp = a->next;
	// 	cur_value = a->value;
	// 	while (temp)
	// 	{
	// 		if (temp->value == cur_value)
	// 			print_error();
	// 		if (temp->next)
	// 			temp = temp->next;
	// 		else
	// 			break;
	// 	}
	// 	a = a->next;
	// }
	// while (a->prev)
	// 	a = a->prev;

int	check_sorted(t_stack *stack)
{
	t_node	*cursor;

	cursor = stack->top;
	while (cursor->next != NULL)
	{
		if (cursor->content > cursor->next->content)
			return (-1);
		cursor = cursor->next;
	}
	return (0);
}

int	check_rev_sorted(t_stack *stack)
{
	t_node *cursor;

	cursor = stack->top;
	while (cursor->next != NULL)
	{
		if (cursor->content < cursor->next->content)
			return (-1);
		cursor = cursor->next;
	}
	return (0);
}


/*
int main(int argc, char **argv)
{
	t_stack	a;
	int no_arg;
	int non_int;
	int dup;
	int	sorted;
	int	i;

	i = 0;
	while(argv[i] != NULL)
	{
		printf("argv[%d]%s\n", i, argv[i]);
		i++;
	}
	non_int= check_non_int(argv);
	init_stack(&a);
	store_to_stack(argv, &a);
//	no_arg = check_no_arg(argc);
	dup = check_duplicate(a.top);
	sorted = check_sorted(&a);
	print_list(&a);
	printf("\nsorted: %d\n", sorted);
	printf("non_int: %d\n", non_int);
	printf("dup: %d\n", dup);

	return (0);
}

*/