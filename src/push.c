/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:36:39 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/03 17:49:21 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

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

void	pa(t_stack_node **a, t_stack_node **b, int print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, int print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
