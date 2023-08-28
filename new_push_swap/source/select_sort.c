/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:02:35 by siun              #+#    #+#             */
/*   Updated: 2023/08/27 14:42:13 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	select_sort(t_list **a, t_list **b)
{
	int count;
	int	tmp;
	t_list	*curr;

	if ((*b) == NULL || b == NULL)
		return ;
	count = 0;
	curr = (*a);
//	ft_printf("curr : %d\n", *(int*)curr->content);
	while (*(int *)curr->content < *(int *)(*b)->content && curr != NULL)
	{
		curr = curr->next;
		count ++;
	}
	
	tmp = 0;
	while (tmp < count)
	{
		ra(a);
		tmp ++;
	}
	pa(a, b);
	while (count > 0)
	{
		rra(a);
		count --;
	}
	return (select_sort(a, b));
}