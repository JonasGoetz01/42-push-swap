/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:02:19 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/01 20:03:31 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_lst_at(t_list *lst, int index)
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
