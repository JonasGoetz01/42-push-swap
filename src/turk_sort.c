/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:45:53 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/04 14:27:43 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief Rotates both stacks until the cheapest node is on top of both stacks.
/// @param a Stack a.
/// @param b Stack b.
/// @param is_cheapest_node The cheapest node in stack a.
static void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rr(a, b, 0);
	current_index(*a);
	current_index(*b);
}

/// @brief Rotates both stacks until the cheapest node is on top of both stacks.
/// @param a Stack a.
/// @param b Stack b.
/// @param cheapest_node The cheapest node in stack a.
static void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rrr(a, b, 0);
	current_index(*a);
	current_index(*b);
}

/// @brief Bring a node from stack a to the top of stack b.
/// @param a Stack a.
/// @param b Stack b.
void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*is_cheapest_node;

	is_cheapest_node = get_is_cheapest(*a);
	if (is_cheapest_node->is_above_median
		&& is_cheapest_node->target->is_above_median)
		rotate_both(a, b, is_cheapest_node);
	else if (!(is_cheapest_node->is_above_median)
		&& !(is_cheapest_node->target->is_above_median))
		rev_rotate_both(a, b, is_cheapest_node);
	prep_for_push(a, is_cheapest_node, 'a');
	prep_for_push(b, is_cheapest_node->target, 'b');
	pb(b, a, 0);
}

/// @brief Bring a node from stack b to the top of stack a.
/// @param a Stack a.
/// @param b Stack b.
void	move_b_to_a(t_node **a, t_node **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b, 0);
}

/// @brief Bring the smallest node to the top of stack a.
/// @param a Stack a.
void	min_on_top(t_node **a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->is_above_median)
			ra(a, 0);
		else
			rra(a, 0);
	}
}
