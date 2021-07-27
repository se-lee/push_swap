/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:32:07 by selee             #+#    #+#             */
/*   Updated: 2021/07/27 16:32:30 by selee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	store_to_stack(char **argv, t_stack *stack)
{
	int	i;
//	t_stack stack;

//	init_stack(&stack);
	i = 1;
	while (argv[i] != NULL)
	{
		add_to_stack_back(stack, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}


