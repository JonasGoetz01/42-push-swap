/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:44:41 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/04 14:39:42 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief Go through the stack and set the is_cheapest flag for the cheapest
/// @param stack The stack.
void	set_is_cheapest(t_node *stack)
{
	long	is_cheapest_value;
	t_node	*is_cheapest_node;

	if (!stack)
		return ;
	is_cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < is_cheapest_value)
		{
			is_cheapest_value = stack->cost;
			is_cheapest_node = stack;
		}
		stack = stack->next;
	}
	is_cheapest_node->is_cheapest = 1;
}

/// @brief Update the index and is_above_median flag for each node in the stack.
/// @param stack The stack.
void	current_index(t_node *stack)
{
	int	i;
	int	m;

	i = 0;
	if (!stack)
		return ;
	m = ft_lst_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= m)
			stack->is_above_median = 1;
		else
			stack->is_above_median = 0;
		stack = stack->next;
		i++;
	}
}
