/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:03:56 by subpark           #+#    #+#             */
/*   Updated: 2023/07/09 17:17:56 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	if (lst == NULL)
		return (NULL);
	curr = lst;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}
/*
#include <stdio.h>
int main()
{
	t_list *tmp2 = ft_lstnew((const char *)"hello?");
	t_list *tmp1 = ft_lstnew((const char *)"what happened ");
	t_list *a = ft_lstnew((const char *)"Nothing ");
	t_list *curr;

	push(&a, tmp1);
	push(&a, tmp2);
	curr = a;
	while (curr != NULL)
	{
		printf("%s \n", curr->content);
		curr = curr->next;
	}
	curr = ft_lstlast(a);
	printf("\n%s\n", curr->content);
	return (0);
}*/