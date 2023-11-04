/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:49:29 by subpark           #+#    #+#             */
/*   Updated: 2023/09/08 13:32:56 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*second;
	t_list	*last;

	if (stack == NULL || *stack == NULL)
		return (0);
	head = *stack;
	second = (*stack)->next;
	last = ft_lstlast(*stack);
	*stack = second;
	last->next = head;
	head->next = NULL;
	return (1);
}

int	ra(t_list **stack_a)
{
	if (!rotate(stack_a))
		return (0);
	ft_printf("ra\n");
	return (1);
}

int	rb(t_list **stack_b)
{
	if (!rotate(stack_b))
		return (0);
	ft_printf("rb\n");
	return (1);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (!rotate(stack_a) || !rotate(stack_b))
		return (0);
	ft_printf("rr\n");
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
		printf("before rotate: %s %p\n", (char *)curr->content, curr->content);
		curr = curr->next;
	}
	rotate(&stack);
	curr = stack;
	while (curr)
	{
		printf("after rotate: %s\n", (char *)curr->content);
		curr = curr->next;
	}
	return 0;
}*/