/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:02:35 by siun              #+#    #+#             */
/*   Updated: 2023/09/08 13:41:09 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_biggest(t_list *a)
{
	t_list	*curr;
	t_list	*big;

	curr = a;
	big = a;
	while (curr)
	{
		if (*(int *)curr->content > *(int *)big->content)
			big = curr;
		curr = curr->next;
	}
	return (big);
}

t_list	*find_smallest(t_list *a)
{
	t_list	*small;
	t_list	*curr;

	small = a;
	curr = a;
	while (curr)
	{
		if (*(int *)curr->content < *(int *)small->content)
			small = curr;
		curr = curr->next;
	}
	return (small);
}
