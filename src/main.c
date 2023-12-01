/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:16:51 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/01 17:17:12 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// /// @brief Swap the first 2 elements at the top of stack a.
// /// Do nothing if there is only one or no elements.
// void	sa(void);

// /// @brief Swap the first 2 elements at the top of stack b.
// /// Do nothing if there is only one or no elements.
// void	sb(void);

// /// @brief sa and sb at the same time.
// void	ss(void);

// /// @brief Take the first element at the top of b and put it at the top of a.
// /// Do nothing if b is empty.
// void	pa(void);

// /// @brief Take the first element at the top of a and put it at the top of b.
// /// Do nothing if a is empty.
// void	pb(void);

// /// @brief Shift up all elements of stack a by 1.
// /// The first element becomes the last one.
// void	ra(void);

// /// @brief Shift up all elements of stack b by 1.
// /// The first element becomes the last one.
// void	rb(void);

// /// @brief ra and rb at the same time.
// void	rr(void);

// /// @brief Shift down all elements of stack a by 1.
// /// The last element becomes the first one.
// void	rra(void);

// /// @brief Shift down all elements of stack b by 1.
// /// The last element becomes the first one.
// void	rrb(void);

// /// @brief rra and rrb at the same time.
// void	rrr(void);

void	fill_stack(t_list **a, char **argv, int argc)
{
	int		i;
	int		j;
	size_t	res;
	char	**tmp;
	t_list	*node;

	i = 1;
	res = 0;
	(void)a;
	while (i < argc)
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[j] != NULL)
		{
			node = ft_lst_new(ft_atoi(tmp[j]));
			ft_lst_add_back(a, node);
			j++;
		}
		i++;
	}
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	(void)b;
	a = (t_list **)malloc(sizeof(t_list *));
	if (!a)
		return (1);
	*a = NULL;
	fill_stack(a, argv, argc);
	printf("%d", ft_lst_size(*a));
	return (0);
}
