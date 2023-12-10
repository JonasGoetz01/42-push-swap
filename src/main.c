/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:40:29 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/10 13:32:07 by jgotz            ###   ########.fr       */
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

static int	is_single_argument(char **argv)
{
	return (argv[1] && !argv[1][0]);
}

static void	process_single_argument(t_node **a, char **argv)
{
	char	**split_argv;

	split_argv = ft_split(argv[1], ' ');
	init_stack_a(a, split_argv);
	free_split(split_argv);
}

static void	handle_sorting(t_node *a, t_node *b)
{
	if (!stack_sorted(a))
	{
		if (ft_lst_size(a) == 2)
			sa(&a, 0);
		else if (ft_lst_size(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || is_single_argument(argv))
		return (1);
	if (argc == 2)
		process_single_argument(&a, argv);
	else
		init_stack_a(&a, argv + 1);
	handle_sorting(a, b);
	free_stack(&a);
	free_stack(&b);
	system("leaks push_swap");
	return (0);
}
