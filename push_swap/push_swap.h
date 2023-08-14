/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 23:04:02 by subpark           #+#    #+#             */
/*   Updated: 2023/08/14 00:25:38 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	tmpdel();
int		ft_lstsize(t_list *lst);
void	connect(t_list **a, t_list *new);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	swap_a(t_list **a);
void	swap_b(t_list **a);
void	sswap(t_list **a, t_list **b);
void	rotate_a(t_list **a);
void	rotate_b(t_list **a);
void	rotaterotate(t_list **a, t_list **b);
void	rerotate_a(t_list **a);
void	rerotate_b(t_list **a);
void	reroro(t_list **a, t_list **b);
int		spc(char c);
void	signs(const char *nptr, int *index, int *sign);
void	select_sort(t_list **a, t_list **b);

#endif