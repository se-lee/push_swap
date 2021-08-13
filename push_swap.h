/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:37 by selee             #+#    #+#             */
/*   Updated: 2021/08/13 12:43:58 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft/libft.h"

# define A 1
# define B 2

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		node_count;
}				t_stack;

typedef struct s_pivcount
{
	int	pivot;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
}				t_pivcount;

/* checks */
int		check_sorted(t_stack *stack);
int		check_non_int(char **argv);
int		check_no_arg(int argc);
int		check_duplicate(t_node *top);

/* stack_prep */
void	init_stack(t_stack *a, t_stack *b);
void	add_to_stack_back(t_stack *stack, t_node *new_node);
void	store_to_stack(char **argv, t_stack *stack);

/* operations */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *b, t_stack *a);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* sort three */
void	sort_two(t_stack *a, t_stack *b, int a_b);
void	a_sort_three(t_stack *a);
void	b_sort_three(t_stack *b);
void	a_three_top_max(t_stack *a);
void	a_three_top_mid(t_stack *a);

/* sort small */
void	a_sort_four(t_stack *a, t_stack *b);
void	b_sort_four(t_stack *a, t_stack *b);
void	sort_less_five(t_stack *a, t_stack *b, int count, int a_b);
void	sort_five(t_stack *a, t_stack *b);

/* quick sort stack */
void	pb_small_ra(t_stack *a, t_stack *b, t_pivcount *pvcnt, int range);
void	pa_big_rb(t_stack *a, t_stack *b, t_pivcount *pvcnt, int range);
void	sort_a(t_stack *a, t_stack *b, int range);
void	sort_b(t_stack *a, t_stack *b, int range);

/* get numbers*/
int		get_min_nbr(t_stack *stack);
int		get_max_nbr(t_stack *stack);
int		get_mid_nbr(t_node *node, int size);
void	get_pivot(t_node *node, int size, t_pivcount *pv);

/* push_swap */
void	push_swap(t_stack *a, t_stack *b);

/* misc */
void	quick_sort(int array[], size_t length);
void	error_exit(void);
void	init_op_count(t_pivcount *count);

/*test functions - to be erased later*/
void	pop_push_min(t_stack *stack1, t_stack *stack2);
void	print_list(t_stack *stack, int a_b);

#endif

/*
エラーケースしっかりやる
*/