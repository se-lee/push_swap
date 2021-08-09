/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:37 by selee             #+#    #+#             */
/*   Updated: 2021/08/09 22:24:17 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft/libft.h"

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		node_count;
}				t_stack;

/* checks */
int		check_sorted(t_stack *stack);
int		check_non_int(char **argv);
int		check_no_arg(int argc);
int		check_duplicate(t_node *top);

/* stack_prep */
void	init_stack(t_stack *stack_a, t_stack *stack_b);
void	add_to_stack(t_stack *stack, t_node *new_node);
void	add_to_stack_back(t_stack *stack, t_node *new_node);
void	store_to_stack(char **argv, t_stack *stack);

/* operations */
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_b, t_stack *stack_a);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/* sort */
void	sort_two_a(t_stack *stack_a);
void	sort_two_b(t_stack *stack_b);
void	sort_three_args(t_stack *stack);
void	three_args_top_max(t_stack *stack);
void	three_args_top_mid(t_stack *stack);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	bubble_sort(int arr[], int size);
void    quick_sort(int array[], size_t length);


/* get numbers*/
int		get_min_nbr(t_stack *stack);
int		get_max_nbr(t_stack *stack);
int		get_mid_nbr(t_node *node, int size);
int		get_avg_nbr(t_stack *stack);
int		get_mid_nbr_five(t_node *node);

/* big */
void	a_to_b(t_stack *stack_a, t_stack *stack_b);


/* misc */
void	error_exit(void);


/*test functions - to be erased later*/
void	pop_push_min(t_stack *stack1, t_stack *stack2);
void	print_list(t_stack *stack_a, t_stack *stack_b);
void	select_sort_list(t_stack *stack1, t_stack *stack2);

#endif
