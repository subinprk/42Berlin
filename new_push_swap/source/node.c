/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:03:58 by subpark           #+#    #+#             */
/*   Updated: 2023/09/11 14:51:11 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_list(t_list *stack, int position)
{
	t_list	*curr;
	int		index;

	index = 0;
	curr = stack;
	while (curr && index < position)
	{
		index = index + 1;
		curr = curr->next;
	}
	if (!curr)
		ft_printf("the order you've requested is out of list length\n");
	return (curr);
}

void	count_cost(t_list **stack)
{
	int		count;
	t_list	*curr;

	curr = *stack;
	count = 0;
	while (curr)
	{
		curr->cost = count;
		curr = curr->next;
	}
	curr = find_list(*stack, count);
	while (curr)
	{
		curr->cost = count;
		count = count - 1;
		curr = curr->next;
	}
}

void	go_forth(t_list	**curr, t_list **prv)
{
	*prv = *curr;
	*curr = (*curr)->next;
}

void	alloc_flag_node(t_list *stack_a, t_list **stack_b)
{
	t_list	*b;
	t_list	*biggest;
	t_list	*smallest;
	t_list	*curr;
	t_list	*prv;

	biggest = find_biggest(stack_a);
	smallest = find_smallest(stack_a);
	b = *stack_b;
	while (b)
	{
		if (*(int *)b->content > *(int *)biggest->content
			|| *(int *)b->content < *(int *)smallest->content)
			b->alloc_node = smallest;
		else
		{
			prv = ft_lstlast(stack_a);
			curr = stack_a;
			while (curr && !(*(int *)prv->content < *(int *)b->content
					&& *(int *)curr->content > *(int *)b->content))
				go_forth(&curr, &prv);
			b->alloc_node = curr;
		}
		b = b->next;
	}
}

t_list	*lowest_cost(t_list *stack_a, t_list *stack_b)
{
	t_list	*curr;
	t_list	*cheapest;

	count_cost(&stack_a);
	count_cost(&stack_b);
	alloc_flag_node(stack_a, &stack_b);
	curr = stack_b;
	cheapest = stack_b;
	while (curr)
	{
		if (curr->cost + curr->alloc_node->cost
			< cheapest->cost + cheapest->alloc_node->cost)
			cheapest = curr;
		curr = curr->next;
	}
	return (cheapest);
}
