/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:38:44 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/04 14:30:28 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief Checks if the input is a valid integer.
/// @param str_n The input string.
/// @return 1 if the input is not a valid integer, 0 otherwise.
int	error_syntax(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || ft_isdigit(*str_n)))
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !ft_isdigit(*(str_n + 1)))
		return (1);
	while (*++str_n)
	{
		if (!ft_isdigit(*str_n))
			return (1);
	}
	return (0);
}

/// @brief Checks if the input is a duplicate.
/// @param a Stack a.
/// @param n The input integer.
/// @return 1 if the input is a duplicate, 0 otherwise.
int	error_duplicate(t_node *a, int n)
{
	while (a && a->value != n)
		a = a->next;
	return (a != NULL);
}

/// @brief Free the stack.
/// @param stack The stack.
void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

/// @brief Free the stack and print "Error".
/// @param a Stack a.
void	free_errors(t_node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(0);
}
