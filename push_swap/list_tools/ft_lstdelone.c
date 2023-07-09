/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:48:16 by subpark           #+#    #+#             */
/*   Updated: 2023/07/09 17:45:54 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

void    tmpdel(void *content)
{
	printf("-----deleted %p-----\n", content);
	return ;
}
/*
#include <stdio.h>
int main()
{
	t_list *lst1 = ft_lstnew((const char *)"hello");
	t_list *lst2 = ft_lstnew((const char *)"what happened ");
	t_list *lst3 = ft_lstnew((const char *)"Nothing ");
	t_list *curr;
	(*lst1).next = lst2;
	(*lst2).next = lst3;
	curr = lst1;
	while (curr != NULL)
	{
		printf("%s \n", curr->content);
		curr = curr->next;
	}
	printf("%d\n",ft_lstsize(lst1));
	printf("%p\n",ft_lstlast(lst1));
	printf("%p\n", lst3);
	ft_lstdelone(ft_lstlast(lst1), tmpdel);
	free (lst1);
	free (lst2);
	return (0);
}*/