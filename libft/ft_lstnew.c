/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 13:17:46 by selee             #+#    #+#             */
/*   Updated: 2020/12/11 13:22:09 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstnew(void *content)
{
	t_node	*new_element;

	new_element = malloc(sizeof(t_node));
	if (!new_element)
		return (NULL);
	(*new_element).content = content;
	(*new_element).next = NULL;
	return (new_element);
}
