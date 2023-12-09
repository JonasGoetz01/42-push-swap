/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:40:29 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/09 15:37:35 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**split_argv;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		init_stack_a(&a, split_argv);
		free_split(split_argv);
	}
	else
		init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (ft_lst_size(a) == 2)
			sa(&a, 0);
		else if (ft_lst_size(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
