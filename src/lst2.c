/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:02:19 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/04 14:34:41 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief Get the node at the given index of a list.
/// @param lst The list.
/// @param index The index.
/// @return The node at the given index.
t_node	*ft_lst_at(t_node *lst, int index)
{
	int	i;

	i = 0;
	while (lst && i < index)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

/// @brief Get the node with the smallest value of the list.
/// @param lst The list.
/// @return The node with the smallest value.
t_node	*ft_lst_min(t_node *lst)
{
	t_node	*min;
	t_node	*tmp;

	min = lst;
	tmp = lst;
	while (tmp)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

/// @brief Get the node with the largest value of the list.
/// @param lst The list.
/// @return The node with the largest value.
t_node	*ft_lst_max(t_node *lst)
{
	t_node	*max;
	t_node	*tmp;

	max = lst;
	tmp = lst;
	while (tmp)
	{
		if (tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}
