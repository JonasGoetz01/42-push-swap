/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:39:41 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/01 19:40:00 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// @brief Shift down all elements of stack a by 1.
/// The last element becomes the first one.
void	rra(t_list **a)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lst_size(*a) >= 2)
	{
		tmp = *a;
		*a = (*a)->next;
		last = ft_lst_last(*a);
		last->next = tmp;
		tmp->next = NULL;
	}
}

/// @brief Shift down all elements of stack b by 1.
/// The last element becomes the first one.
void	rrb(t_list **b)
{
	rra(b);
}

/// @brief rra and rrb at the same time.
void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
