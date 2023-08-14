/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:48:37 by subpark           #+#    #+#             */
/*   Updated: 2023/08/14 17:29:20 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_list **a)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*curr;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last = ft_lstlast((*a));
	tmp = ft_lstnew(last->content);
	tmp->next = *(a);
	curr = *(a);
	while (curr->next->next != NULL)
		curr = curr->next;
	curr->next = NULL;
	ft_lstdelone(last);
	*a = tmp;
	printf ("ra\n");
}

void	rotate_b(t_list **a)
{
	t_list	*tmp;
	t_list	*last;

	last = ft_lstlast(*a);
	tmp = ft_lstnew(last->content);
	tmp->next = *(a);
	while (((**a).next)->next != NULL)
		*a = (*a)->next;
	(*a)->next = NULL;
	ft_lstdelone(last);
	*a = tmp;
	printf("rb\n");
}

void	rotaterotate(t_list **a, t_list **b)
{
	rotate_a(a);
	rotate_b(b);
}
/*
#include <stdio.h>
int main()
{
	t_list *tmp2 = ft_lstnew((const char *)"hello?");
	t_list *tmp1 = ft_lstnew((const char *)"what happened ");
	t_list *a = ft_lstnew((const char *)"Nothing ");
	t_list *curr;

	t_list *t2 = ft_lstnew((const char *)"hi");
	t_list *t1 = ft_lstnew((const char *)"what happened!");
	t_list *b = ft_lstnew((const char *)"Nothing! ");

	push(&a, tmp1);
	push(&a, tmp2);
	push(&b, t1);
	push(&b, t2);
	rotaterotate(&a, &b);
	curr = a;
	while (curr != NULL)
	{
		printf("%s \n", curr->content);
		curr = curr->next;
	}
	curr = b;
	while (curr != NULL)
	{
		printf("%s \n", curr->content);
		curr = curr->next;
	}
	ft_lstclear(&a, tmpdel);
	ft_lstclear(&b, tmpdel);
	return (0);
}*/