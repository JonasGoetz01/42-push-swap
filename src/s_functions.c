/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:36:34 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/01 19:40:04 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// @brief Swap the first 2 elements at the top of stack a.
/// Do nothing if there is only one or no elements.
void	sa(t_list **a)
{
	int	tmp;

	if (ft_lst_size(*a) >= 2)
	{
		tmp = a[0]->value;
		a[0]->value = a[1]->value;
		a[1]->value = tmp;
	}
}

/// @brief Swap the first 2 elements at the top of stack b.
/// Do nothing if there is only one or no elements.
void	sb(t_list **b)
{
	sa(b);
}

/// @brief sa and sb at the same time.
void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}
