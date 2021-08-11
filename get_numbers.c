/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:25:59 by selee             #+#    #+#             */
/*   Updated: 2021/08/11 01:13:23 by seoyounglee      ###   ########lyon.fr   */
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

/*---- これいらんかもね -----*/
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
/*---- これいらんかもね -----*/


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
	return (nbr[size / 2]);
}

void		get_pivot(t_node *node, int size, t_pivcount *pv)
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

	// i = 0;
	// while (i < size)
	// {
	// 	printf("%d  ", nbr[i]);
	// 	i++;
	// }

	pv->piv_big = nbr[size / 2];
	pv->piv_small = nbr[size / 4];	
}

/*
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_pivot pv;

	init_stack(&a, &b);
	store_to_stack(argv, &a);
	
	pv = get_pivot(a.top, a.node_count);
//	print_list(&a, &b);
	
	printf("\npv_big:%d  ", pv.piv_big);
	printf("pv_small:%d  \n", pv.piv_small);

	return (0);
}
*/

