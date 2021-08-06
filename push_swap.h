/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:37 by selee             #+#    #+#             */
/*   Updated: 2021/08/07 00:05:33 by seoyounglee      ###   ########lyon.fr   */
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

/* operations */
void	swap(t_stack* stack, char stack_name);
void	pop_and_push(t_stack *stack1, t_stack *stack2);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);

/* checks */
int check_sorted(t_stack *stack);
int	check_non_int(char **argv);
int	check_no_arg(int argc);
int	check_duplicate(char **argv);


/* sort */
void	sort_three_args(t_stack *stack);
void	three_args_top_max(t_stack *stack);
void	three_args_top_mid(t_stack *stack);
int		get_min_nbr(t_stack *stack);
int		get_max_nbr(t_stack *stack);


/*test functions - to be erased later*/
void	pop_push_min(t_stack *stack1, t_stack *stack2);
void	print_list(t_stack *stack);
void	select_sort_list(t_stack *stack1, t_stack *stack2);

#endif
