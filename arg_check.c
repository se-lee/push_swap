/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:33:03 by selee             #+#    #+#             */
/*   Updated: 2021/08/17 04:05:27 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_is_int(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '+' || argv[0] == '-')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	arg_over_int_max_min(char *argv)
{
	int				i;
	int				sign;
	int				arg_len;
	unsigned long	nbr;

	i = 0;
	sign = 1;
	arg_len = ft_strlen(argv);
	nbr = 0;
	if (argv[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			nbr = nbr * 10 + (argv[i] - '0');
		i++;
	}
	if (arg_len > 11 || (sign == 1 && nbr > INT_MAX)
		|| (sign == -1 && nbr > INT_MIN))
		return (1);
	return (0);
}

int	arg_has_error(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!arg_is_int(argv[i]) || arg_over_int_max_min(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
