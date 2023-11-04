/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:36:43 by subpark           #+#    #+#             */
/*   Updated: 2023/11/03 21:13:50 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_b, t_list **stack_a);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
void	select_sort(t_list **a, t_list **b);
t_list	*find_list(t_list *stack, int position);
void	count_cost(t_list **stack);
long	load_args(int argc, char **argv, t_list **stack_a);
int		check_multiple(t_list *stack);
void	make_order_3(t_list **stack_a);
long	load_stack_one(char *str, t_list **lst);
long	load_stack(char	*num, t_list **lst);
t_list	*find_biggest(t_list *a);
t_list	*find_smallest(t_list *a);
void	alloc_flag_node(t_list *stack_a, t_list **stack_b);
t_list	*lowest_cost(t_list *stack_a, t_list *stack_b);
void	move(t_list **stack_a, t_list **stack_b);
int		having_2_case(t_list **stack_a);
int		check_sorted(t_list *stack);
int		order_in_stack(t_list *stack, t_list *target);

#endif
