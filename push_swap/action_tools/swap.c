/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 23:01:09 by subpark           #+#    #+#             */
/*   Updated: 2023/06/23 00:47:52 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **a)
{
	t_list *na;

	na = (*a) -> next;
	(*a) -> next = na -> next;
	na -> next = (*a);
	*a = na;
}

void	swapswap(t_list **a, t_list *b)
{
	swap(a);
	swap(b);
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

	t_list *arg;

	push(&a, tmp1);
	push(&a, tmp2);
	push(&b, t1);
	push(&b, t2);

	arg = a;
	while (arg != NULL)
	{
		printf("this is original a: ");
		printf("%s \n", arg->content);
		arg = arg->next;
	}
	arg = b;
	while (arg != NULL)
	{
		printf("	this is original b:  ");
		printf("%s \n", arg->content);
		arg = arg->next;
	}
	swapswap(&a, &b);
	arg = a;
	while (arg != NULL)
	{
		printf("this is modified a:  ");
		printf("%s \n", arg->content);
		arg = arg->next;
	}
	arg = b;
	while (arg != NULL)
	{
		printf("	this is modified b: ");
		printf("%s \n", arg->content);
		arg = arg->next;
	}
	return (0);
}*/