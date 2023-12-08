/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:46:25 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/04 14:41:45 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief The sorting algorithm.
///
/// The algorithm works as follows:
/// 1. If the stack is smaller than 4, sort it with sort_three.
/// 2. If the stack is larger than 3, push the cheapest node to stack b.
/// 3. If the stack is larger than 3, push the second cheapest node to stack b.
/// 4. While the stack is larger than 3, push the cheapest node to stack b.
/// @param a Stack a.
/// @param b Stack b.
void	sort_stacks(t_node **a, t_node **b)
{
	int	len_a;

	len_a = ft_lst_size(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, 0);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, 0);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
