/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:37 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 00:22:07 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#if DEBUG
#define debug(f, ...) f(__VA_ARGS__)
#else
#define debug(f, ...)
#endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN 2147483648

typedef enum {
	pa, pb,
	ra, rb, rr,
	sa, sb, ss,
	rra, rrb, rrr,
} t_instruction;

typedef struct s_program_node {
	t_instruction instruction;
	struct s_program_node *next;
} t_program_node;

typedef struct  {
	t_program_node *first;
	t_program_node *last;
} t_program;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		node_count;
}				t_stack;

typedef struct {
	t_stack a;
	t_stack b;
	t_program program;
} t_push_swap;

typedef struct s_op_count
{
	int	pa_count;
	int	pb_count;
	int	ra_count;
	int	rb_count;
}				t_op_count;

/* program */
void	program_init(t_program *program);
void	program_add_instruction(t_program *program, t_instruction instruction);
void	program_optimize(t_program *program);
void	program_run(t_program *program);
void	program_free(t_program *program);

/* arg check */
int		arg_is_int(char *argv);
int		arg_over_int_max_min(char *argv);
int		arg_has_error(char **argv);

/* stack check */
int		stack_has_duplicate(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
int		stack_is_reverse_sorted(t_stack *stack);

/* stack_utils */
void	stack_init(t_stack *stack);
void	stack_add_node_back(t_stack *stack, t_node *new_node);
void	stack_store_value(char **argv, t_stack *stack);
void	stack_free(t_stack *stack);
void	stack_free_all(t_stack *a, t_stack *b);

/* operation functions (op_) */
void	op_swap_a(t_push_swap *ps);
void	op_swap_b(t_push_swap *ps);
void	op_swap_all(t_push_swap *ps);
void	op_push_to_a(t_push_swap *ps);
void	op_push_to_b(t_push_swap *ps);
void	op_rotate_a(t_push_swap *ps);
void	op_rotate_b(t_push_swap *ps);
void	op_rotate_all(t_push_swap *ps);
void	op_reverse_rotate_a(t_push_swap *ps);
void	op_reverse_rotate_b(t_push_swap *ps);
void	op_reverse_rotate_all(t_push_swap *ps);

/* find numbers*/
int		find_min_value_in_range(t_node *node, int range);
int		find_mid_value_in_range(t_node *node, int range);
int		find_max_value_in_range(t_node *node, int range);

/* sort three a */
void	sort_two_a(t_push_swap *ps);
void 	sort_a_3(t_push_swap *ps);

/* sort three reverse */
void	sort_two_reverse_b(t_push_swap *ps);
void 	sort_b_3(t_push_swap *ps);

/* quick sort stack a */
t_op_count	partition_a_in_range(t_push_swap *ps, int range);
void	quick_sort_a(t_push_swap *ps, int range);

/* quick sort stack b */
t_op_count	partition_b_in_range(t_push_swap *ps, int range);
void	quick_sort_b(t_push_swap *ps, int range);

/* push_swap */
void	push_swap_solve(t_push_swap *ps);

/* push swap utils */
void	init_op_count(t_op_count *count);
void	print_error_exit(void);
void	quick_sort(int array[], size_t length);

#endif
