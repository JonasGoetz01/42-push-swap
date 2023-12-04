/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:37:57 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/04 14:39:12 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief A sorting routine for three nodes.
/// @param a Stack a.
void	sort_three(t_node **a)
{
	t_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, 0);
	else if ((*a)->next == biggest_node)
		rra(a, 0);
	if ((*a)->value > (*a)->next->value)
		sa(a, 0);
}
