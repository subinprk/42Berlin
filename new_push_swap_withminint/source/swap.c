/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:10:00 by subpark           #+#    #+#             */
/*   Updated: 2023/09/08 13:43:47 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*second;

	if (stack == NULL || *stack == NULL)
		return (0);
	head = *stack;
	second = (*stack)->next;
	*stack = second;
	head->next = second->next;
	second->next = head;
	return (1);
}

int	sa(t_list **stack_a)
{
	if (!swap(stack_a))
		return (0);
	ft_printf("sa\n");
	return (1);
}

int	sb(t_list **stack_b)
{
	if (!swap(stack_b))
		return (0);
	ft_printf("sb\n");
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
		printf("before swap: %s %p\n", (char *)curr->content, curr->content);
		curr = curr->next;
	}
	swap(&stack);
	curr = stack;
	while (curr)
	{
		printf("after rotate: %s\n", (char *)curr->content);
		curr = curr->next;
	}
	return 0;
}*/