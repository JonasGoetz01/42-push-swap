/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:36:39 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/04 14:36:26 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief Pushes the first node of src to the first node of dst.
/// @param dst Destination stack.
/// @param src Source stack.
static void	push(t_node **dst, t_node **src)
{
	t_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = push_node->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	push_node->next = *dst;
	if (*dst)
		(*dst)->prev = push_node;
	*dst = push_node;
}

/// @brief Pushes the first node of a to the first node of b.
/// @param a Stack a.
/// @param b Stack b.
/// @param print If true, the function will not print.
void	pa(t_node **a, t_node **b, int print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

/// @brief Pushes the first node of b to the first node of a.
/// @param b Stack b.
/// @param a Stack a.
/// @param print If true, the function will not print.
void	pb(t_node **b, t_node **a, int print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
