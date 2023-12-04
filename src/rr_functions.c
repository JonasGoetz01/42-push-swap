/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:36:56 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/04 14:38:14 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief Rotates the stack by moving the last node to the top.
/// @param stack The stack.
static void	rev_rotate(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

/// @brief Rotates stack a.
/// @param a Stack a.
/// @param print If true, the function will not print.
void	rra(t_node **a, int print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

/// @brief Rotates stack b.
/// @param b Stack b.
/// @param print If true, the function will not print.
void	rrb(t_node **b, int print)
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

/// @brief Rotates both stacks.
/// @param a Stack a.
/// @param b Stack b.
/// @param print If true, the function will not print.
void	rrr(t_node **a, t_node **b, int print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}
