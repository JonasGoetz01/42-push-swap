/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:47:43 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/09 18:01:16 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_instruction(t_instruction **instructions)
{
	int		ret;
	char	line[4];

	ft_bzero(line, 4);
	ret = read(STDIN_FILENO, line, 3);
	if (ret <= 0)
		return (ret);
	if (line[2] != '\n')
	{
		if (line[0] == '\n' || line[1] == '\n')
			return (-1);
		if (read(STDIN_FILENO, line + 3, 1) < 0 || line[3] != '\n')
			return (-1);
		line[3] = '\0';
	}
	else
		line[2] = '\0';
	if (ft_strncmp(line, "sa", 3) && ft_strncmp(line, "sb", 3)
		&& ft_strncmp(line, "ss", 3) && ft_strncmp(line, "pa", 3)
		&& ft_strncmp(line, "pb", 3) && ft_strncmp(line, "ra", 3)
		&& ft_strncmp(line, "rb", 3) && ft_strncmp(line, "rr", 3)
		&& ft_strncmp(line, "rra", 3) && ft_strncmp(line, "rrb", 3)
		&& ft_strncmp(line, "rrr", 3))
		return (-1);
	return (push_instruction(instructions, line));
}

int	init_instructions(t_instruction **instructions)
{
	int	ret;

	ret = get_instruction(instructions);
	while (ret > 0)
		ret = get_instruction(instructions);
	if (ret < 0)
	{
		free_instructions(*instructions);
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}

int	is_sorted(t_node *stack_a, t_node *stack_b)
{
	int		num;
	t_node	*tmp;

	if (stack_b)
		return (0);
	if (!stack_a)
		return (0);
	num = stack_a->value;
	tmp = stack_a->next;
	while (tmp)
	{
		if (num > tmp->value)
			return (0);
		num = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}

void	print_stack(t_node *stack_a, t_node *stack_b)
{
	ft_printf("stack_a:\n");
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	ft_printf("stack_b:\n");
	while (stack_b)
	{
		ft_printf("%d\n", stack_b->value);
		stack_b = stack_b->next;
	}
}

int	add_instruction(t_instruction **instructions, char *line)
{
	t_instruction	*new;
	t_instruction	*last;

	new = new_instruction(line);
	if (!new)
		return (-1);
	if (!(*instructions))
		*instructions = new;
	else
	{
		last = last_instruction(*instructions);
		last->next = new;
	}
	return (1);
}
