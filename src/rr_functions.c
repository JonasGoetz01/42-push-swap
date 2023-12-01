/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:39:41 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/01 20:12:46 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// @brief Shift down all elements of stack a by 1.
/// The last element becomes the first one.
void rra(t_list **a)
{
    t_list *tmp;
    t_list *last;

    if (ft_lst_size(*a) >= 2)
    {
        last = *a;
        while (last->next->next != NULL)
            last = last->next;

        tmp = last->next;
        last->next = NULL;
        tmp->next = *a;
        *a = tmp;
    }
    printf("rra\n");
}

/// @brief Shift down all elements of stack b by 1.
/// The last element becomes the first one.
void	rrb(t_list **b)
{
	rra(b);
	printf("rrb\n");
}

/// @brief rra and rrb at the same time.
void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	printf("rrr\n");
}
