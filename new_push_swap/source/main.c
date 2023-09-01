/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:10:37 by subpark           #+#    #+#             */
/*   Updated: 2023/08/31 14:44:56 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	load_stack(char	*num, t_list **lst)
{
	t_list	*new;
	int		*number;

	number = (int *)malloc(sizeof(int));
	if (!number)
		return (0);
	*number = ft_atoi(num);
	if ((*number) == 0)
		return (0);
	new = ft_lstnew(number);
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstadd_front(lst, new);
	return (1);
}

int	load_stack_one(char *str, t_list **lst)
{
	int *number;
	int	i;
	char	**splited;
	t_list	*new;

	splited = ft_split(str, ' ');
	i = 0;
	while (splited[i])
	{
		number = (int *)malloc(sizeof(int));
		if (!number)
			return (-1);
		*number = ft_atoi(splited[i]);
		if (!(*number))
			return (0);
		new = ft_lstnew(number);
		if (*lst == NULL)
			*lst = new;
		else
			ft_lstadd_front(lst, new);
		i ++;
	}
	return (i + 1);
}

void	make_order_3(t_list **stack_a)
{
	t_list	*st;
	t_list	*nd;
	t_list	*rd;

	st = *stack_a;
	nd = (*stack_a)->next;
	rd = ((*stack_a)->next)->next;

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
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (2 == argc && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argc = load_stack_one(argv[1], &stack_a);
		if (!argc)
		{
			ft_printf("Error\n");
			return (1);
		}
	}
	else
	{
		i = 1;
		while (i < argc)
			if(!load_stack(argv[i ++], &stack_a))
			{
				ft_printf("Error\n");
				return (1);
			}
	}
	j = 0;
	while (j < argc - 4)
	{
		pb(&stack_b, &stack_a);
		j ++;
	}
	make_order_3(&stack_a);
	select_sort(&stack_a, &stack_b);
	curr = stack_a;
	while (curr)
	{
		ft_printf("stack a: %d\n", *(int *)curr->content);
		//ft_printf("current pointer: %p, next pointer: %p\n", curr, curr->next);
		next = curr->next;
		curr = next;
	}
	ft_lstclear(&stack_a, free);
	return (0);
}