/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:37 by selee             #+#    #+#             */
/*   Updated: 2021/08/14 18:53:58 by selee            ###   ########lyon.fr   */
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
int		stack_is_sorted(t_stack *stack);
int		is_sorted_reverse(t_stack *stack); //"stack_~~~" - be consistent
void	check_non_int(char **argv);
int		check_no_arg(int argc);
int		check_duplicate(t_node *top);

/* stack_prep */
void	init_stack(t_stack *a, t_stack *b); //"stack~ " to be consistent (prefix)
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
void	sort_two(t_stack *a, t_stack *b, int a_b); //be more specific
void	sort_two_stack_a(t_stack *a);
void	sort_two_reverse_stack_b(t_stack *b);
void	a_sort_three(t_stack *a); //a or b_ doesnt mean anything. describe more precisely; 
void	b_sort_three(t_stack *b); 
void	a_three_top_max(t_stack *a);
void	a_three_top_mid(t_stack *a);

/* sort small */
void	a_sort_four(t_stack *a, t_stack *b);
void	b_sort_four(t_stack *a, t_stack *b);
void	sort_less_five(t_stack *a, t_stack *b, int count, int a_b);
void	sort_five(t_stack *a, t_stack *b);
void	push_back_a(t_stack *a, t_stack *b, int count);

/* quick sort stack */
int		range_is_sorted(t_stack *a, t_stack *stack_b, int range, int a_b);
void	pb_small_ra(t_stack *a, t_stack *b, t_pivcount *pvcnt);
void	pa_big_rb(t_stack *a, t_stack *b, t_pivcount *pvcnt);
// void	sort_a(t_stack *a, t_stack *b, int range);
// void	sort_b(t_stack *a, t_stack *b, int range); //think about using unsigned
void	quick_sort_a(t_stack *a, t_stack *b, int range);
void	quick_sort_b(t_stack *a, t_stack *b, int range);


/* get numbers*/
int		get_min_nbr(t_stack *stack);
int		get_max_nbr(t_stack *stack);
int		get_mid_nbr(t_node *node, int size);
int		get_pivot(t_node *node, int range);
//void	get_pivot(t_node *node, int size, t_pivcount *pv);

/* push_swap */
void	push_swap(t_stack *a, t_stack *b);

/* misc */
void	quick_sort(int array[], size_t length);
void	init_op_count(t_pivcount *count);

/*test functions - to be erased later*/
void	print_list(t_stack *stack, char a_b);

#endif
