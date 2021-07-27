#include "push_swap.h"
#include <stdio.h>
//find the minimum number
//compare
//sort

void	seleciton_sort(int arr[], int size)
{
	int min;
	int	i;
	int	j;
	int temp;

	i = 0;
	temp = 0;
	min = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
			j++;
		}
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
		i++;
	}
}

void	selection_sort(t_stack *stack1, t_stack *stack2)
{
	int		min;
	t_node	*cursor;

	cursor = stack1->top;
	min = cursor->content;

	while(cursor != NULL)
	{
		if ()
	}

}


