/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:38:40 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/01 19:40:08 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// @brief Shift up all elements of stack a by 1.
/// The first element becomes the last one.
void	ra(t_list **a)
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

/// @brief Shift up all elements of stack b by 1.
/// The first element becomes the last one.
void	rb(t_list **b)
{
	ra(b);
}

/// @brief ra and rb at the same time.
void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}
