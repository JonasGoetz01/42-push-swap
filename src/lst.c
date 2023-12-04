/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:01:37 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/04 14:33:19 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief Add a new node to the end of the list.
/// @param lst The list.
/// @param new The new node.
void	ft_lst_add_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (lst)
	{
		if (!(*lst))
		{
			*lst = new;
			new->prev = NULL;
		}
		else
		{
			last = ft_lst_last(*lst);
			last->next = new;
			new->prev = last;
		}
	}
}

/// @brief Add a new node to the front of the list.
/// @param lst The list.
/// @param new The new node.
void	ft_lst_add_front(t_node **lst, t_node *new)
{
	if (lst)
	{
		if (!(*lst))
		{
			*lst = new;
			new->prev = NULL;
		}
		else
		{
			new->next = *lst;
			(*lst)->prev = new;
			*lst = new;
		}
	}
}

/// @brief Get the last node of the list.
/// @param lst The list.
/// @return The last node of the list.
t_node	*ft_lst_last(t_node *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

/// @brief Create a new node
/// @param value The value of the node.
/// @return The new node.
t_node	*ft_lst_new(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/// @brief Get the size of the list.
/// @param lst The list.
/// @return The size of the list.
int	ft_lst_size(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
