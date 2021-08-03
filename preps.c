/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:32:07 by selee             #+#    #+#             */
/*   Updated: 2021/08/04 00:49:06 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	store_to_stack(char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		add_to_stack_back(stack, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}

//need a function to convert 


