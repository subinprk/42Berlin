/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:51:44 by subpark           #+#    #+#             */
/*   Updated: 2023/06/26 17:25:17 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rerotate(t_list **a)
{
	t_list	*tmp;
	t_list	*curr;

	tmp = ft_lstnew((*a)->content);
	ft_lstlast(*a)->next = tmp;
	curr = *a;
	*a = (*a)->next;
	ft_lstdelone(curr, tmpdel);
}

void	reroro(t_list **a, t_list **b)
{
	rerotate(a);
	rerotate(b);
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
	rerotate(&a);
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