/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 23:01:09 by subpark           #+#    #+#             */
/*   Updated: 2023/07/09 23:56:01 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **a)
{
	t_list *na;

	na = (*a) -> next;
	(*a) -> next = na -> next;
	na -> next = (*a);
	*a = na;
}
void	sswap(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}