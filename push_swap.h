/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:37 by selee             #+#    #+#             */
/*   Updated: 2021/07/27 16:31:39 by selee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		node_count;
}				t_stack;

void	init_stack(t_stack *stack);
void	add_to_stack_back(t_stack *stack, t_node *new_node);
void	init_stack(t_stack *stack);
void	add_to_stack(t_stack *stack, t_node *new_node); //push
void	store_to_stack(char **argv, t_stack *stack);
void	print_list(t_stack *stack);//erase this later

/*operations*/
void	swap(t_stack *stack, t_node *node1, t_node *node2); //revise
void	pop_and_push(t_stack *stack1, t_stack *stack2);

#endif

/*
- get arguments
- check errors
- check whether sorted or not
- if sorted, do nothing and finish
- if not sorted, sort

when sorting



*/