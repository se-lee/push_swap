/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 04:14:01 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 05:45:33 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_op_count(t_op_count *count)
{
	count->pa_count = 0;
	count->pb_count = 0;
	count->ra_count = 0;
	count->rb_count = 0;
}

void	print_error_exit(t_push_swap *ps)
{
	ft_putendl_fd("Error", 2);
	push_swap_free(ps);
	exit(0);
}
