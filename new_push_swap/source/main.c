/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:10:37 by subpark           #+#    #+#             */
/*   Updated: 2023/08/27 15:02:38 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	load_stack(char	*num, t_list **lst)
{
	t_list	*new;
	int		*number;

	number = (int *)malloc(sizeof(int));
	if (!number)
		return ;
	*number = ft_atoi(num);
	new = ft_lstnew(number);
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstadd_front(lst, new);
}

void	make_order_3(t_list **stack_a)
{
	t_list	*st;
	t_list	*nd;
	t_list	*rd;

	st = *stack_a;
	nd = (*stack_a)->next;
	rd = ((*stack_a)->next)->next;
//	printf("1st a: %d\n", *(int *)(st->content));
//	printf("2nd a: %d\n", *(int *)(nd->content));
//	printf("3rd a: %d\n", *(int *)(rd->content));

	if (*(int *)(st->content) < *(int *)(nd->content) && *(int *)(st->content) < *(int *)(rd->content)
		&& *(int *)(rd->content) > *(int *)(nd->content) && *(int *)(rd->content) > *(int *)(st->content))
		return ;
	else if (*(int *)(rd->content) < *(int *)(nd->content) && *(int *)(rd->content) < *(int *)(st->content)
		&& *(int *)(nd->content) > *(int *)(st->content) && *(int *)(nd->content) > *(int *)(rd->content))
	{
		ra(stack_a);
		return (make_order_3(stack_a));
	}
	else if (*(int *)(nd->content) < *(int *)(rd->content) && *(int *)(nd->content) < *(int *)(st->content)
		&& *(int *)(st->content) > *(int *)(nd->content) && *(int *)(st->content) > *(int *)(rd->content))
	{
		ra(stack_a);
		return (make_order_3(stack_a));
	}
	else
	{
		sa(stack_a);
		return (make_order_3(stack_a));
	}
}


int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*curr;
	t_list	*next;

	if (argc <= 1)
		return(0);
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i < argc)
		load_stack(argv[i ++], &stack_a);
	
	j = 0;
	while (j < i - 4)
	{
		pb(&stack_b, &stack_a);
		j ++;
	}
	make_order_3(&stack_a);
	select_sort(&stack_a, &stack_b);
	curr = stack_a;
	/*while (curr)
	{
	//	ft_printf("stack a: %d\n", *(int *)curr->content);
	//	ft_printf("current pointer: %p, next pointer: %p\n", curr, curr->next);
		next = curr->next;
		curr = next;
	}*/
	ft_lstclear(&stack_a, free);
/*	curr = stack_b;
	while (curr)
	{
		ft_printf("stack b : %d\n", *(int *)curr->content);
		next = curr->next;
		curr = next;
	}
	ft_lstclear(&stack_b, free);*/
	return (0);
}