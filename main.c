/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 04:22:05 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 17:39:45 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;

	stack_init(&push_swap.a);
	stack_init(&push_swap.b);
	if (argc <= 1)
		return (0);
	if (arg_has_error(argv))
		print_error_exit(&push_swap);
	stack_store_value(&push_swap, argv, &push_swap.a);
	if (stack_has_duplicate(&push_swap.a))
		print_error_exit(&push_swap);
	push_swap_solve(&push_swap);
	push_swap_free(&push_swap);
	return (0);
}
