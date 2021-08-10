/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:25:59 by selee             #+#    #+#             */
/*   Updated: 2021/08/10 03:02:15 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

//これいらんかもね
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
	quick_sort(nbr, size);
	i = 0;
	while (i < size)
	{
		printf("%d  ", nbr[i]);
		i++;
	}
	printf("\n");
	return (nbr[size / 2]);
}


t_pivot		get_pivot(t_stack *stack, int size)
{
	t_pivot 	pv;

	pv.piv_big = get_mid_nbr(stack->top, size); //スタック全体の中央値
	pv.piv_small = get_mid_nbr(stack->top, (size / 2)); //スタックの前の半分の中央値

printf("size: %d  \n", size/2);
	return (pv);
}

/*
get each node->content, store into int array
do quick sor

*/

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_pivot pv;

	init_stack(&a, &b);
	store_to_stack(argv, &a);
	
	pv = get_pivot(&a, a.node_count);
	print_list(&a, &b);
	
	printf("\npv_big:%d  ", pv.piv_big);
	printf("pv_small:%d  \n", pv.piv_small);

	return (0);
}



