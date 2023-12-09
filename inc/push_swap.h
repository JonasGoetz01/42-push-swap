/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:04:07 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/09 15:30:26 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ft_printf.h"
# include <limits.h>

typedef struct s_instruction
{
	char			*instructions;
	void			*next;
}					t_instruction;

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	int				is_above_median;
	int				is_cheapest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

void				free_split(char **split);

int					error_syntax(char *str_n);
int					error_duplicate(t_node *a, int n);
void				free_stack(t_node **stack);
void				free_errors(t_node **a);

void				init_stack_a(t_node **a, char **argv);

void				init_nodes_a(t_node *a, t_node *b);
void				init_nodes_b(t_node *a, t_node *b);
void				current_index(t_node *stack);
void				set_is_cheapest(t_node *stack);
t_node				*get_is_cheapest(t_node *stack);
void				prep_for_push(t_node **s, t_node *n, char c);

t_node				*find_last(t_node *stack);
int					stack_sorted(t_node *stack);
t_node				*find_min(t_node *stack);
t_node				*find_max(t_node *stack);

void				sa(t_node **a, int print);
void				sb(t_node **b, int print);
void				ss(t_node **a, t_node **b, int print);
void				ra(t_node **a, int print);
void				rb(t_node **b, int print);
void				rr(t_node **a, t_node **b, int print);
void				rra(t_node **a, int print);
void				rrb(t_node **b, int print);
void				rrr(t_node **a, t_node **b, int print);
void				pa(t_node **a, t_node **b, int print);
void				pb(t_node **b, t_node **a, int print);

void				sort_three(t_node **a);
void				sort_stacks(t_node **a, t_node **b);

void				move_b_to_a(t_node **a, t_node **b);
void				move_a_to_b(t_node **a, t_node **b);
void				min_on_top(t_node **a);

void				ft_lst_add_back(t_node **lst, t_node *new);
void				ft_lst_add_front(t_node **lst, t_node *new);
t_node				*ft_lst_last(t_node *lst);
t_node				*ft_lst_new(int value);
int					ft_lst_size(t_node *lst);
t_node				*ft_lst_at(t_node *lst, int index);
t_node				*ft_lst_min(t_node *lst);
t_node				*ft_lst_max(t_node *lst);

#endif
