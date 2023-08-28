/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:36:43 by subpark           #+#    #+#             */
/*   Updated: 2023/08/26 10:22:39 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

int	pa(t_list **stack_a, t_list **stack_b);
int pb(t_list **stack_b, t_list **stack_a);
int	rra(t_list **stack_a);
int	rrb(t_list **stack_b);
int	ra(t_list **stack_a);
int	rb(t_list **stack_b);
int	sa(t_list **stack_a);
int	sb(t_list **stack_b);
void	select_sort(t_list **a, t_list **b);

#endif
