/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:12:30 by subpark           #+#    #+#             */
/*   Updated: 2023/09/11 14:52:11 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_multiple(t_list *stack)
{
	t_list	*all;
	t_list	*check;

	check = stack;
	while (check)
	{
		all = check->next;
		while (all)
		{
			if (*(int *)all->content == *(int *)check->content)
				return (0);
			all = all->next;
		}
		check = check->next;
	}
	return (1);
}

int	check_sorted(t_list *stack)
{
	t_list	*curr;
	t_list	*prv;

	curr = stack->next;
	prv = stack;
	while (curr)
	{
		if (*(int *)prv->content > *(int *)curr->content)
			return (0);
		prv = curr;
		curr = curr->next;
	}
	return (1);
}

int	having_2_case(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) == 2)
	{
		sa(stack_a);
		return (1);
	}
	else
		return (0);
}

int	order_in_stack(t_list *stack, t_list *target)
{
	int		i;
	t_list	*curr;

	curr = stack;
	i = 0;
	while (curr && curr != target)
	{
		i = i + 1;
		curr = curr->next;
	}
	if (curr == target)
		return (i);
	else
		return (-1);
}
