/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:37 by selee             #+#    #+#             */
/*   Updated: 2021/08/15 16:57:36 by seoyounglee      ###   ########lyon.fr   */
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
	int	pa_count;
	int	pb_count;
	int	ra_count;
	int	rb_count;
}				t_pivcount;

/* checks */
int		arg_is_int(char **argv);
int		stack_has_duplicate(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
int		stack_is_reverse_sorted(t_stack *stack);

/* stack_utils */
//void	stack_init(t_stack *stack);
t_stack stack_init(void);
void	stack_add_node_back(t_stack *stack, t_node *new_node);
void	stack_store_value(char **argv, t_stack *stack);
void	stack_free(t_stack *stack);
void	print_list(t_stack *stack, char a_b);

/* operation functions (op_) */
void	op_swap_a(t_stack *a);
void	op_swap_b(t_stack *b);
void	op_swap_all(t_stack *a, t_stack *b);
void	op_push_to_a(t_stack *b, t_stack *a);
void	op_push_to_b(t_stack *a, t_stack *b);
void	op_rotate_a(t_stack *a);
void	op_rotate_b(t_stack *b);
void	op_rotate_all(t_stack *a, t_stack *b);
void	op_reverse_rotate_a(t_stack *a);
void	op_reverse_rotate_b(t_stack *b);
void	op_reverse_rotate_all(t_stack *a, t_stack *b);

/* get numbers*/
int		find_min_value_in_range(t_node *node, int range);
int		find_mid_value_in_range(t_node *node, int range);
int		find_max_value_in_range(t_node *node, int range);

//int		find_pivot(t_node *node, int range);
//void	get_pivot(t_node *node, int size, t_pivcount *pv);

/* sort upto three */
void	sort_two_a(t_stack *a);
void	sort_three_a(t_stack *a);

/* sort upto three reverse */
void	sort_two_reverse_b(t_stack *b);
void	sort_three_reverse_b(t_stack *b);

/* sort small */
void	sort_four_a(t_stack *a, t_stack *b);
void	sort_four_reverse_b(t_stack *a, t_stack *b);
void	sort_less_five(t_stack *a, t_stack *b, int count);
//void	sort_less_five(t_stack *a, t_stack *b, int count, int a_b);
void	sort_five(t_stack *a, t_stack *b);
void	push_back_a(t_stack *a, t_stack *b, int count); // maybe no

/* quick sort stack */
int		range_is_sorted(t_stack *a, t_stack *stack_b, int range, int a_b);
void	pb_small_ra(t_stack *a, t_stack *b, t_pivcount *pvcnt);
void	pa_big_rb(t_stack *a, t_stack *b, t_pivcount *pvcnt);
// void	sort_a(t_stack *a, t_stack *b, int range);
// void	sort_b(t_stack *a, t_stack *b, int range); //think about using unsigned
void	quick_sort_a(t_stack *a, t_stack *b, int range);
void	quick_sort_b(t_stack *a, t_stack *b, int range);

/* push_swap */
void	push_swap(t_stack *a, t_stack *b);

/* misc */
void	quick_sort(int array[], size_t length);
void	init_op_count(t_pivcount *count);
void	print_error_exit(void);

/*test functions - to be erased later*/

#endif
