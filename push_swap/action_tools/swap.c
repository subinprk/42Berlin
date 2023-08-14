/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 23:01:09 by subpark           #+#    #+#             */
/*   Updated: 2023/08/13 23:57:34 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_list **a)
{
	t_list *na;

	na = (*a) -> next;
	(*a) -> next = na -> next;
	na -> next = (*a);
	*a = na;
	printf("sa\n");
}

void	swap_b(t_list **a)
{
	t_list *na;

	na = (*a) -> next;
	(*a) -> next = na -> next;
	na -> next = (*a);
	*a = na;
	printf("sb\n");
}

void	sswap(t_list **a, t_list **b)
{
	swap_a(a);
	swap_b(b);
}