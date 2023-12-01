/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:16:51 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/01 19:41:51 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

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

void	print_lst(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	(void)b;
	a = (t_list **)malloc(sizeof(t_list *));
	b = (t_list **)malloc(sizeof(t_list *));
	if (!a || !b)
		return (1);
	*a = NULL;
	*b = NULL;
	fill_stack(a, argv, argc);
	return (0);
}
