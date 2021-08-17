/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:25:59 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 16:54:43 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_mid_value_in_range_a(
	t_push_swap *ps,
	t_stack *stack,
	int range)
{
	int		i;
	int		result;
	int		*nbr;
	t_node	*cursor;

	nbr = malloc(sizeof(int) * range);
	if (!nbr)
		print_error_exit(ps);
	i = 0;
	cursor = stack->top;
	while (i < range)
	{
		nbr[i] = cursor->content;
		cursor = cursor->next;
		i++;
	}
	quick_sort(nbr, range);
	result = nbr[range / 2 - 1];
	free(nbr);
	return (result);
}

int	find_mid_value_in_range_b(
	t_push_swap *ps, t_stack *stack, int range)
{
	int		i;
	int		result;
	int		*nbr;
	t_node	*cursor;

	nbr = malloc(sizeof(int) * range);
	if (!nbr)
		print_error_exit(ps);
	i = 0;
	cursor = stack->top;
	while (i < range)
	{
		nbr[i] = cursor->content;
		cursor = cursor->next;
		i++;
	}
	quick_sort(nbr, range);
	result = nbr[range / 2];
	free(nbr);
	return (result);
}
