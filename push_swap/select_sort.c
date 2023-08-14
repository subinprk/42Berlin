/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:02:35 by siun              #+#    #+#             */
/*   Updated: 2023/08/14 00:26:41 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_sort(t_list **a, t_list **b)
{
	int count;

	if ((*b) == NULL)
		return ;
	count = 0;
	while ((*a)->content < (*b)->content)
	{
		rerotate_a(a);
		count ++;
	}
	push_a(a, b);
	while (count > 0)
	{
		rotate_a(a);
		count --;
	}
	return (select_sort(a, b));
}