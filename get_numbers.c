#include "push_swap.h"

int		get_min_nbr(t_stack *stack)
{
	int	min;
	t_node	*temp;

	min = stack->top->content;
	temp = stack->top;
	while (stack)
	{
		if (temp->content < min)
			min = temp->content;
		if (temp->next)
			temp = temp->next;
		else
			break;
	}
	return (min);
}

int		get_max_nbr(t_stack *stack)
{
	int	max;
	t_node *temp;

	max = stack->top->content;
	temp = stack->top;
	while (stack)
	{
		if (temp->content > max)
			max = temp->content;
		if (temp->next)
			temp = temp->next;
		else
			break;
	}
	return (max);
}


int		get_avg_nbr(t_stack *stack)
{
	int	avg;
	int	min;
	int	max;

	min = get_min_nbr(stack);
	max = get_max_nbr(stack);
	avg = (min + max) / 2;
	return (avg);
}

/* revise: modify to handle three arguments too. get_mid above is lame. */
int		get_mid_nbr_five(t_node *node)
{
	int	i;
	int	nbr[5];

	i = 0;
	while(i < 5)
	{
		nbr[i] = node->content;
		node = node->next;
		i++;
	}
	bubble_sort(nbr, 5);
	return (nbr[2]);
}

int		get_mid_nbr(t_node *node, int size)
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
	bubble_sort(nbr, size);
	return (nbr[size / 2]);
}

// int		get_pivot(t_stack *stack)
// {
// 	int	i;
// 	int	pivot;
// }

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int	mid;

	init_stack(&a, &b);
	store_to_stack(argv, &a);
	
	mid = get_mid_nbr(a.top, a.node_count);
	printf("mid: %d \n", mid);

	return (0);
}



