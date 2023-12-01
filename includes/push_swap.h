/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:18:57 by jgotz             #+#    #+#             */
/*   Updated: 2023/12/01 17:02:27 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

void				ft_lst_add_back(t_list **lst, t_list *new);
t_list				*ft_lst_last(t_list *lst);
t_list				*ft_lst_new(int value);
int					ft_lst_size(t_list *lst);

#endif