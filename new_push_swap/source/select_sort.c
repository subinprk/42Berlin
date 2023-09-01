/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:02:35 by siun              #+#    #+#             */
/*   Updated: 2023/09/01 13:24:08 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_biggest(t_list *a)
{
	t_list	*curr;
	t_list	*big;

	curr = a;
	big = a;
	while(curr)
	{
		if (*(int *)curr->content > *(int *)big->content)
			big = curr;
		curr = curr->next;
	}
	return (big);
}

t_list *find_smallest(t_list *a)
{
	t_list	*small;
	t_list	*curr;

	small = a;
	curr = a;
	while (curr)
	{
		if(*(int *)curr->content < *(int *)small->content)
		small = curr;
		curr = curr->next;
	}
	return (small);
}

void	select_sort(t_list **a, t_list **b)
{
	static int count;
	int	tmp;
	t_list	*curr;
	//static t_list	*start;

	if (b == NULL)
		return ;
	//curr = (*a);
	//start = (*a);
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
	if ((*b) != NULL && *(int *)find_biggest(*a)->content < *(int *)(*b)->content)
	{
		while (*a != find_biggest(*a))
			ra(a);
		pa(a, b);
	}
	else if ((*b) != NULL && *(int *)find_smallest(*a)->content > *(int *)(*b)->content)
	{
		while (*a != find_smallest(*a))
			rra(a);
		pa(a, b);
	}
	else if ((*b) != NULL && *(int *)(*a)->content < *(int *)(*b)->content)//have to fix here, it doesn't cover the case b->content is biggist
			ra(a);
	else if ((*b) != NULL && *(int *)(*a)->content > *(int *)(*b)->content && *(int *)ft_lstlast((*a))->content > *(int *)(*b)->content)
		rra(a);
	else if (*b != NULL && *(int *)(*a)->content > *(int *)(*b)->content && *(int *)ft_lstlast((*a))->content < *(int *)(*b)->content)
		pa(a, b);
	else if (*b == NULL && *(int *)ft_lstlast((*a))->content < *(int *)(*a)->content)
			rra(a);
	else
		return ;
	return (select_sort(a, b));
}