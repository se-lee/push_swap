/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:25:59 by selee             #+#    #+#             */
/*   Updated: 2021/08/15 15:11:17 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_value_in_range(t_node *node, int range)
{
	int	i;
	int	min;
	t_node	*temp;

	i = 0;
	min = node->content;
	temp = node;
	while (i < range)
	{
		if (temp->content < min)
			min = temp->content;
		if (temp->next)
			temp = temp->next;
		else
			break ;
		i++;
	}
	return (min);
}

int	find_max_value_in_range(t_node *node, int range)
{
	int	i;
	int	max;
	t_node *temp;

	i = 0;
	max = node->content;
	temp = node;
	while (i < range)
	{
		if (temp->content > max)
			max = temp->content;
		if (temp->next)
			temp = temp->next;
		else
			break;
		i++;
	}
	return (max);
}

int	find_mid_value_in_range(t_node *node, int size)
{
	int	i;
	int	nbr[size];

	i = 0;
	while (i < size)
	{
		nbr[i] = node->content;
		node = node->next;
		i++;
	}
	quick_sort(nbr, size);
	i = (size + 1) / 2 - 1;
	return (nbr[i]);
}

/*
int	main(int argc, char **argv)
{
	t_stack	a;
//	t_stack	b;

	if (argc < 1)
		return 0;
	stack_init(&a);
	stack_store_value(argv, &a);

	printf("min: %d  ", find_min_value_in_range(a.top, 5));

	return (0);
}
*/