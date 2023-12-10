/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:37:30 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/10 15:53:31 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief Rotates the stack by moving the first node to the end.
/// @param stack The stack.
static void	rotate(t_node **stack)
{
	t_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

/// @brief Rotates stack a.
/// @param a Stack a.
/// @param print If true, the function will not print.
void	ra(t_node **a, int print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

/// @brief Rotates stack b.
/// @param b Stack b.
/// @param print If true, the function will not print.
void	rb(t_node **b, int print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

/// @brief Rotates both stacks.
/// @param a Stack a.
/// @param b Stack b.
/// @param print If true, the function will not print.
void	rr(t_node **a, t_node **b, int print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}
