/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:56:17 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/01 21:02:36 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// @brief Function to partition the list and return the pivot index
/// @param a the stack a
/// @param low
/// @param high
/// @return the pivot index
static int	partition(t_list **a, int low, int high)
{
	int		pivot;
	int		i;
	t_list	*node;
	t_list	*pivot_node;

	node = *a;
	for (i = 0; i < low; i++)
	{
		if (!node)
			break ;
		node = node->next;
	}
	pivot_node = node;
	for (i = low; i < high; i++)
	{
		if (!pivot_node)
			break ;
		pivot_node = pivot_node->next;
	}
	if (!pivot_node)
		return (high - 1); // Return the last index to avoid issues
	pivot = pivot_node->value;
	i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (node && node->next && node->value < pivot)
		{
			i++;
			ra(a);
			sa(a);
		}
		if (node)
			node = node->next;
	}
	if (node)
		ra(a);
	sa(a);
	return (i);
}

/// @brief Recursive function to implement quick sort
/// @param a the stack a
/// @param low
/// @param high
static void	quick_sort_helper(t_list **a, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(a, low, high);
		quick_sort_helper(a, low, pi);
		quick_sort_helper(a, pi + 1, high);
	}
}

/// @brief Wrapper function for quick sort
/// @param a the stack a
void	quick_sort(t_list **a)
{
	int	size;

	size = ft_lst_size(*a);
	if (size > 0)
		quick_sort_helper(a, 0, size);
}
