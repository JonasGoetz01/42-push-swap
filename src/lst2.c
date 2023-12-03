/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:02:19 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/03 14:59:44 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack_node	*ft_lst_at(t_stack_node *lst, int index)
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

t_stack_node	*ft_lst_min(t_stack_node *lst)
{
	t_stack_node	*min;
	t_stack_node	*tmp;

	min = lst;
	tmp = lst;
	while (tmp)
	{
		if (tmp->nbr < min->nbr)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_stack_node	*ft_lst_max(t_stack_node *lst)
{
	t_stack_node	*max;
	t_stack_node	*tmp;

	max = lst;
	tmp = lst;
	while (tmp)
	{
		if (tmp->nbr > max->nbr)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}
