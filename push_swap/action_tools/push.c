/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:22:30 by subpark           #+#    #+#             */
/*   Updated: 2023/08/13 22:40:15 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	connect(t_list **a, t_list *new)
{
	new->next = *a;
	*a = new;
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*t;

	tmp = ft_lstnew((*b)->content);
	tmp->next = *a;
	*a = tmp;
	t = *b;
	*b = (*b)->next;
	ft_lstdelone(t, tmpdel);
	printf("pa\n");
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*t;

	tmp = ft_lstnew((*b)->content);
	tmp->next = *a;
	*a = tmp;
	t = *b;
	*b = (*b)->next;
	ft_lstdelone(t, tmpdel);
	printf("pb\n");
}

/*
#include <stdio.h>
int main()
{
	t_list *tmp2 = ft_lstnew((const char *)"hello?");
	t_list *tmp1 = ft_lstnew((const char *)"what happened ");
	t_list *a = ft_lstnew((const char *)"Nothing ");

	t_list *t2 = ft_lstnew((const char *)"hi");
	t_list *t1 = ft_lstnew((const char *)"what happened!");
	t_list *b = ft_lstnew((const char *)"Nothing! ");

	connect(&a, tmp1);
	connect(&a, tmp2);
	connect(&b, t1);
	connect(&b, t2);
	push(&a, &b);
	t_list *curr;
	curr = a;
	while (curr != NULL)
	{
		printf("%s \n", curr->content);
		curr = curr->next;
	}
	printf("\n");
	curr = b;
	while (curr != NULL)
	{
		printf("%s \n", curr->content);
		curr = curr->next;
	}
	ft_lstclear(&a, tmpdel);
	ft_lstclear(&b, tmpdel);
	printf("%s\n", a->content);
	a = a->next;
	printf("%s\n", a->content);
	a = a->next;
	printf("%s\n", a->content);
	printf("%d", a->next);
	a = a->next;
	printf("%p", a);
	return (0);
}*/