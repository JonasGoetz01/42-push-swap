/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:38:18 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/04 14:38:55 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief Swaps the first two nodes of the stack.
/// @param head The stack.
static void	swap(t_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

/// @brief Swaps the first two nodes of stack a.
/// @param a Stack a.
/// @param print If true, the function will not print.
void	sa(t_node **a, int print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

/// @brief Swaps the first two nodes of stack b.
/// @param b Stack b.
/// @param print If true, the function will not print.
void	sb(t_node **b, int print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

/// @brief Swaps the first two nodes of both stacks.
/// @param a Stack a.
/// @param b Stack b.
/// @param print If true, the function will not print.
void	ss(t_node **a, t_node **b, int print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
