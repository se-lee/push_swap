/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:37 by selee             #+#    #+#             */
/*   Updated: 2021/08/12 15:57:21 by selee            ###   ########lyon.fr   */
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
void	init_stack(t_stack *stack_a, t_stack *stack_b);
void	add_to_stack(t_stack *stack, t_node *new_node); //これ使ってないと思う
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


/* sort three */
void	sort_two(t_stack *stack_a, t_stack *stack_b, int a_or_b);
void	a_sort_three(t_stack *stack);
void	b_sort_three(t_stack *stack_b);
void	a_three_top_max(t_stack *stack);
void	a_three_top_mid(t_stack *stack);

/* sort small */
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_less_five(t_stack *stack_a, t_stack *stack_b, int count, int a_or_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);


/* quick sort stack */
void	pb_small_ra(t_stack *stack_a, t_stack *stack_b, t_pivcount *pvcnt, int range); //does rra
void	pa_big_rb(t_stack *stack_a, t_stack *stack_b, t_pivcount *pvcnt, int range); // does rrb
void	a_to_b_sort(t_stack *stack_a, t_stack *stack_b, int range);
void	b_to_a_sort(t_stack *stack_a, t_stack *stack_b, int range);


/* get numbers*/
int		get_min_nbr(t_stack *stack);
int		get_max_nbr(t_stack *stack);
int		get_mid_nbr(t_node *node, int size);
int		get_avg_nbr(t_stack *stack);  //多分これも消す
void	get_pivot(t_node *node, int size, t_pivcount *pv);

/* push_swap */
void	push_swap(t_stack *stack_a, t_stack *stack_b);

/* misc */
void    quick_sort(int array[], size_t length);
void	error_exit(void);
void	init_op_count(t_pivcount *count);

/*test functions - to be erased later*/
void	pop_push_min(t_stack *stack1, t_stack *stack2);
void	print_list(t_stack *stack_a, char flag);
void	select_sort_list(t_stack *stack1, t_stack *stack2);
void	display_stacks(t_stack *stack[2], char *message);

#endif


/*
ドリアンのクイックソート見直す。。復習復習
エラーケースしっかりやる

あああ
終わらない
なんでこんなむずいの
もやもやするよおおおおおお

*/