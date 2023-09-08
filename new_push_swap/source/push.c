/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:36:00 by subpark           #+#    #+#             */
/*   Updated: 2023/09/08 13:36:54 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push(t_list **origin, t_list **target)
{
	t_list	*head_origin;
	t_list	*head_target;

	if (!origin || !(*origin))
		return (0);
	head_origin = *origin;
	head_target = *target;
	*origin = (*origin)->next;
	head_origin->next = head_target;
	*target = head_origin;
	return (1);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a))
	{
		ft_printf("pa\n");
		return (1);
	}
	else
	{
		ft_printf("pa error\n");
		return (0);
	}
}

int	pb(t_list **stack_b, t_list **stack_a)
{
	if (push(stack_a, stack_b))
	{
		ft_printf("pb\n");
		return (1);
	}
	else
	{
		ft_printf("pb error\n");
		return (0);
	}
}
/*
int main()
{
    t_list node1 = {"1", NULL};
    t_list node2 = {"2", NULL};

    t_list *origin = &node1;
    t_list *target = NULL;

    printf("Before push:\n");
    printf("Origin: %s\n", (origin->content));
   // printf("Target: %s\n", (target->content));

    push(&origin, &target);

    printf("\nAfter push:\n");
   // printf("Origin: %d\n", origin->content);
    printf("Target: %s\n", target->content);
	//printf("Target next: %s\n", target->next->content);

    return 0;
}*/