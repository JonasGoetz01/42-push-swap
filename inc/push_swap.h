/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:04:07 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/03 14:55:41 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ft_printf.h"
# include <limits.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	int					above_median;
	int					cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

int						error_syntax(char *str_n);
int						error_duplicate(t_stack_node *a, int n);
void					free_stack(t_stack_node **stack);
void					free_errors(t_stack_node **a);

void					init_stack_a(t_stack_node **a, char **argv);

void					init_nodes_a(t_stack_node *a, t_stack_node *b);
void					init_nodes_b(t_stack_node *a, t_stack_node *b);
void					current_index(t_stack_node *stack);
void					set_cheapest(t_stack_node *stack);
t_stack_node			*get_cheapest(t_stack_node *stack);
void					prep_for_push(t_stack_node **s, t_stack_node *n,
							char c);

t_stack_node			*find_last(t_stack_node *stack);
int					stack_sorted(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);

void					sa(t_stack_node **a, int print);
void					sb(t_stack_node **b, int print);
void					ss(t_stack_node **a, t_stack_node **b, int print);
void					ra(t_stack_node **a, int print);
void					rb(t_stack_node **b, int print);
void					rr(t_stack_node **a, t_stack_node **b, int print);
void					rra(t_stack_node **a, int print);
void					rrb(t_stack_node **b, int print);
void					rrr(t_stack_node **a, t_stack_node **b, int print);
void					pa(t_stack_node **a, t_stack_node **b, int print);
void					pb(t_stack_node **b, t_stack_node **a, int print);

void					sort_three(t_stack_node **a);
void					sort_stacks(t_stack_node **a, t_stack_node **b);

void					move_b_to_a(t_stack_node **a, t_stack_node **b);
void					move_a_to_b(t_stack_node **a, t_stack_node **b);
void					min_on_top(t_stack_node **a);

void					ft_lst_add_back(t_stack_node **lst, t_stack_node *new);
void					ft_lst_add_front(t_stack_node **lst, t_stack_node *new);
t_stack_node			*ft_lst_last(t_stack_node *lst);
t_stack_node			*ft_lst_new(int value);
int						ft_lst_size(t_stack_node *lst);
t_stack_node			*ft_lst_at(t_stack_node *lst, int index);
t_stack_node			*ft_lst_min(t_stack_node *lst);
t_stack_node			*ft_lst_max(t_stack_node *lst);

#endif
