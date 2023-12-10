/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:48:32 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/10 14:22:48 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_instruction	*last_instruction(t_instruction *instructions)
{
	while (instructions->next)
		instructions = instructions->next;
	return (instructions);
}

int	push_instruction(t_instruction **instructions, char *line)
{
	t_instruction	*new;
	t_instruction	*last;

	new = ft_calloc(1, sizeof(t_instruction));
	if (!new)
		return (1);
	new->instructions = ft_strdup(line);
	new->next = NULL;
	if (!(*instructions))
		*instructions = new;
	else
	{
		last = last_instruction(*instructions);
		last->next = new;
	}
	return (1);
}

void	free_instructions(t_instruction *instructions)
{
	t_instruction	*next;

	while (instructions)
	{
		next = instructions->next;
		free(instructions->instructions);
		free(instructions);
		instructions = next;
	}
}

void	execute_instructions2(t_instruction *inst, t_node **a, t_node **b)
{
	if (inst->instructions != NULL)
	{
		if (!ft_strncmp(inst->instructions, "ra", 3)
			|| !ft_strncmp(inst->instructions, "rr", 3))
			ra(a, 1);
		else if (!ft_strncmp(inst->instructions, "rb", 3)
			|| !ft_strncmp(inst->instructions, "rr", 3))
			rb(b, 1);
		else if (!ft_strncmp(inst->instructions, "rra", 3)
			|| !ft_strncmp(inst->instructions, "rrr", 3))
			rra(a, 1);
		else if (!ft_strncmp(inst->instructions, "rrb", 3)
			|| !ft_strncmp(inst->instructions, "rrr", 3))
			rrb(b, 1);
	}
}

void	execute_instructions(t_instruction *inst, t_node **a, t_node **b)
{
	while (inst)
	{
		if (inst->instructions != NULL)
		{
			if (!ft_strncmp(inst->instructions, "sa", 3)
				|| !ft_strncmp(inst->instructions, "ss", 3))
				sa(a, 1);
			else if (!ft_strncmp(inst->instructions, "sb", 3)
				|| !ft_strncmp(inst->instructions, "ss", 3))
				sb(b, 1);
			else if (!ft_strncmp(inst->instructions, "pa", 3))
				pa(a, b, 1);
			else if (!ft_strncmp(inst->instructions, "pb", 3))
				pb(b, a, 1);
			else
				execute_instructions2(inst, a, b);
		}
		inst = inst->next;
	}
}
