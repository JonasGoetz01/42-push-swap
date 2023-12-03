/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:01:37 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/03 14:45:11 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_lst_add_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*last;

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

void	ft_lst_add_front(t_stack_node **lst, t_stack_node *new)
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

t_stack_node	*ft_lst_last(t_stack_node *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

t_stack_node	*ft_lst_new(int value)
{
	t_stack_node	*new;

	new = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->nbr = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	ft_lst_size(t_stack_node *lst)
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
