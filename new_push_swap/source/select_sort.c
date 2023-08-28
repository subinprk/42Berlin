/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:02:35 by siun              #+#    #+#             */
/*   Updated: 2023/08/28 13:49:21 by subpark          ###   ########.fr       */
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
	//ft_printf("curr : %d\n", *(int*)curr->content);
	while (curr != NULL && *(int *)curr->content < *(int *)(*b)->content)
	{
	//	ft_printf("I'm in this number now: %d\n", *(int*)curr->content);
		curr = curr->next;
		count ++;
	}
	//ft_printf("count : %d\n", count);
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