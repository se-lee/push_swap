/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:26:09 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 04:17:31 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

size_t	partition(int array[], size_t length)
{
	int		pivot;
	size_t	index;
	size_t	pivot_index;

	index = 1;
	pivot_index = 0;
	pivot = array[0];
	while (index < length)
	{
		if (array[index] < pivot)
		{
			pivot_index += 1;
			swap(&array[index], &array[pivot_index]);
		}
		index += 1;
	}
	swap(&array[0], &array[pivot_index]);
	return (pivot_index);
}

void	quick_sort(int array[], size_t length)
{
	int	pivot_index;

	if (length <= 1)
		return ;
	pivot_index = partition(array, length);
	quick_sort(&array[0], pivot_index);
	quick_sort(&array[pivot_index + 1], length - (pivot_index + 1));
}
