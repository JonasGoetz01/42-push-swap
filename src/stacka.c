/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacka.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:39:33 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/04 14:23:42 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief Set the target index for each node in stack a.
/// @param a Stack a.
/// @param b Stack b.
static void	set_target_a(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

/// @brief Set the cost for each node in stack a to go to the target location.
/// @param a Stack a.
/// @param b Stack b.
static void	cost_analysis_a(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lst_size(a);
	len_b = ft_lst_size(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->is_above_median))
			a->cost = len_a - (a->index);
		if (a->target->is_above_median)
			a->cost += a->target->index;
		else
			a->cost += len_b - (a->target->index);
		a = a->next;
	}
}

/// @brief Sorting routine for stack a.
/// @param a Stack a.
/// @param b Stack b.
void	init_nodes_a(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_is_cheapest(a);
}
