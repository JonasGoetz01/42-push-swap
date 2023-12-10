/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:44:36 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/10 15:54:50 by jgotz            ###   ########.fr       */
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

void	initialize_stack(char *str, t_node **stack)
{
	int		i;
	long	num;
	char	**split;

	i = 0;
	split = ft_split(str, ' ');
	while (split[i])
	{
		if (!ft_isdigit(split[i][0]) && split[i][0] != '-')
		{
			ft_printf("Error\n");
			return ;
		}
		num = atol(split[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_printf("Error\n");
			return ;
		}
		ft_lst_add_back(stack, ft_lst_new((int)num));
		i++;
	}
	free_split(split);
}

t_instruction	*new_instruction(char *instructions)
{
	t_instruction	*new;

	new = ft_calloc(1, sizeof(t_instruction));
	if (!new)
		return (NULL);
	new->instructions = ft_strdup(instructions);
	new->next = NULL;
	return (new);
}

int	main(int argc, char **argv)
{
	t_node			*stack_a;
	t_node			*stack_b;
	t_instruction	**instructions;

	if (argc != 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	stack_a = NULL;
	stack_b = NULL;
	instructions = malloc(sizeof(t_instruction *));
	(void)argv;
	init_stack_a(&stack_a, ft_split("4 67 3 87 23", ' '));
	init_instructions(instructions);
	execute_instructions(*instructions, &stack_a, &stack_b);
	if (is_sorted(stack_a, stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	return (0);
}
