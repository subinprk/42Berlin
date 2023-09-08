/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:23:49 by siun              #+#    #+#             */
/*   Updated: 2023/09/08 13:39:38 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rerotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;
	t_list	*b4last;

	if (stack == NULL || *stack == NULL)
		return (0);
	head = *stack;
	last = ft_lstlast(*stack);
	b4last = *stack;
	while (b4last->next != last)
		b4last = b4last->next;
	b4last->next = NULL;
	*stack = last;
	last->next = head;
	return (1);
}

int	rra(t_list **stack_a)
{
	if (!rerotate(stack_a))
		return (0);
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_list **stack_b)
{
	if (!rerotate(stack_b))
		return (0);
	ft_printf("rrb\n");
	return (1);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (!rerotate(stack_a) || !rerotate(stack_b))
		return (0);
	ft_printf("rrr\n");
	return (1);
}

/*
int main()
{
	t_list *node1;
	t_list *node2;
	t_list *node3;
	t_list *stack;
	t_list  *curr;
   // int     tmpnum;

	stack = NULL;
  //  tmpnum = 1;
	node1 = ft_lstnew("1");
 //   tmpnum  = 2;
	node2 = ft_lstnew("2");
   // tmpnum = 3;
	node3 = ft_lstnew("3");

	ft_lstadd_front(&stack, node1);
	ft_lstadd_front(&stack, node2);
	ft_lstadd_front(&stack, node3);
	curr = stack;
	while (curr != NULL)
	{
		printf("before rerotate: %s %p\n", (char *)curr->content, curr->content);
		curr = curr->next;
	}
	rerotate(&stack);
	curr = stack;
	while (curr)
	{
		printf("after rerotate: %s\n", (char *)curr->content);
		curr = curr->next;
	}
	return 0;
}*/