/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:02:35 by siun              #+#    #+#             */
/*   Updated: 2023/08/30 17:00:45 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	select_sort(t_list **a, t_list **b)
{
	static int count;
	int	tmp;
	t_list	*curr;

	if (b == NULL)
		return ;
	curr = (*a);
	/*//ft_printf("curr : %d\n", *(int*)curr->content);
	if (*(int *)curr->content > *(int *)(*b)->content)
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
	}*/
	if ((*b) != NULL && *(int *)curr->content < *(int *)(*b)->content)//have to fix here, it doesn't cover the case b->content is biggist
		ra(a);
	else if ((*b) != NULL && *(int *)curr->content > *(int *)(*b)->content && *(int *)ft_lstlast(curr)->content > *(int *)(*b)->content)
		rra(a);
	else if ((*b) != NULL && *(int *)curr->content > *(int *)(*b)->content && *(int *)ft_lstlast(curr)->content < *(int *)(*b)->content)
		pa(a, b);
	else if ((*b) == NULL && *(int *)ft_lstlast(curr)->content < *(int *)curr->content)
		rra(a);
	else
		return ;
	return (select_sort(a, b));
}