/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:22:30 by subpark           #+#    #+#             */
/*   Updated: 2023/06/23 00:36:43 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **a, t_list *new)
{
	new->next = *a;
	*a = new;
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

	push(&a, tmp1);
	push(&a, tmp2);
	while (a != NULL)
	{
		printf("%s \n", a->content);
		a = a->next;
	}
	return (0);
}*/