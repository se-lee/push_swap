/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:37 by selee             #+#    #+#             */
/*   Updated: 2021/07/28 13:11:35 by selee            ###   ########lyon.fr   */
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
void	add_to_stack(t_stack *stack, t_node *new_node);
void	store_to_stack(char **argv, t_stack *stack);

/*operations*/
void	swap(t_stack *stack, t_node *node1, t_node *node2);
void	pop_and_push(t_stack *stack1, t_stack *stack2);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);

/*test functions - to be erased later*/
void	selection_sort_list(t_stack *stack1, t_stack *stack2);
void	print_list(t_stack *stack);


#endif
