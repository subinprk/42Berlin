/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:51:44 by subpark           #+#    #+#             */
/*   Updated: 2023/08/15 15:21:57 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rerotate_a(t_list **a)
{
	t_list	*tmp;
	t_list	*curr;
	int		*number;

	number = (int *)malloc(sizeof(int));
	if (!number)
		return ;
	*number = *(int *)((*a)->content);
	tmp = ft_lstnew(number);
	(ft_lstlast(*a))->next = tmp;
	curr = *a;
	*a = (*a)->next;
	ft_lstdelone(curr);
	printf("rra\n");
}

void	rerotate_b(t_list **a)
{
	t_list	*tmp;
	t_list	*curr;

	tmp = ft_lstnew((*a)->content);
	ft_lstlast(*a)->next = tmp;
	curr = *a;
	*a = (*a)->next;
	ft_lstdelone(curr);
	printf("rrb\n");
}

void	reroro(t_list **a, t_list **b)
{
	rerotate_a(a);
	rerotate_b(b);
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

	ft_lstadd_front(&a, tmp1);
	ft_lstadd_front(&a, tmp2);
	rerotate_a(&a);
	curr = a;
	while (curr != NULL)
	{
		printf("%s \n", curr->content);
		curr = curr->next;
	}
	/*curr = b;
	while (curr != NULL)
	{
		printf("%s \n", curr->content);
		curr = curr->next;
	}
	ft_lstclear(&a, tmpdel);
	ft_lstclear(&b, tmpdel);
	return (0);
}*/