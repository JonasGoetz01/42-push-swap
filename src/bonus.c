/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:44:36 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/09 15:23:39 by jgotz            ###   ########.fr       */
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

t_instruction	*last_instruction(t_instruction *instructions)
{
	while (instructions->next)
		instructions = instructions->next;
	return (instructions);
}

void	push_instruction(t_instruction **instructions, char *line)
{
	t_instruction	*new;
	t_instruction	*last;

	new = ft_calloc(1, sizeof(t_instruction));
	if (!new)
		return ;
	new->instructions = ft_strdup(line);
	new->next = NULL;
	if (!(*instructions))
		*instructions = new;
	else
	{
		last = last_instruction(*instructions);
		last->next = new;
	}
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

void	execute_instructions(t_instruction *instr, t_node **stack_a,
		t_node **stack_b)
{
	// array static const
	while (instr)
	{
		if (!ft_strncmp(instr->instructions, "sa", 3)
			|| !ft_strncmp(instr->instructions, "ss", 3))
			sa(stack_a, 1);
			if (!ft_strncmp(instr->instructions, "sb", 3)
			|| !ft_strncmp(instr->instructions, "ss", 3))
			sb(stack_b, 1);
		if (!ft_strncmp(instr->instructions, "pa", 3))
			pa(stack_a, stack_b, 1);
		if (!ft_strncmp(instr->instructions, "pb", 3))
			pb(stack_b, stack_a, 1);
		if (!ft_strncmp(instr->instructions, "ra", 3)
			|| !ft_strncmp(instr->instructions, "rr", 3))
			ra(stack_a, 1);
		if (!ft_strncmp(instr->instructions, "rb", 3)
			|| !ft_strncmp(instr->instructions, "rr", 3))
			rb(stack_b, 1);
		if (!ft_strncmp(instr->instructions, "rra", 3)
			|| !ft_strncmp(instr->instructions, "rrr", 3))
			rra(stack_a, 1);
		if (!ft_strncmp(instr->instructions, "rrb", 3)
			|| !ft_strncmp(instr->instructions, "rrr", 3))
			rrb(stack_b, 1);
		instr = instr->next;
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
	push_instruction(instructions, line);
	return (1);
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
	init_stack_a(&stack_a, ft_split(argv[1], ' '));
	init_instructions(instructions);
	execute_instructions(*instructions, &stack_a, &stack_b);
	if (is_sorted(stack_a, stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	return (0);
}
