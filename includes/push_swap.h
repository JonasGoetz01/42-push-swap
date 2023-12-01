/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:18:57 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/01 20:07:19 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

void				ft_lst_add_back(t_list **lst, t_list *new);
void				ft_lst_add_front(t_list **lst, t_list *new);
t_list				*ft_lst_last(t_list *lst);
t_list				*ft_lst_new(int value);
int					ft_lst_size(t_list *lst);
t_list				*ft_lst_at(t_list *lst, int index);

void				pa(t_list **a, t_list **b);
void				pb(t_list **a, t_list **b);
void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);
void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);
void				sa(t_list **a);
void				sb(t_list **b);
void				ss(t_list **a, t_list **b);

void				quick_sort(t_list **a);

#endif