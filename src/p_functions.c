/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:37:17 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/01 19:40:10 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// @brief Take the first element at the top of b and put it at the top of a.
/// Do nothing if b is empty.
void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
	}
}

/// @brief Take the first element at the top of a and put it at the top of b.
/// Do nothing if a is empty.
void	pb(t_list **a, t_list **b)
{
	pa(b, a);
}
