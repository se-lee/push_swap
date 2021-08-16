/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:25:59 by selee             #+#    #+#             */
/*   Updated: 2021/08/16 23:45:52 by selee            ###   ########lyon.fr   */
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
	return (nbr[size / 2]);
}
