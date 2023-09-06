/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:10:37 by subpark           #+#    #+#             */
/*   Updated: 2023/09/06 14:04:23 by subpark          ###   ########.fr       */
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
	int	j;
	char	**splited;
	t_list	*new;

	splited = ft_split(str, ' ');
	i = 0;
	while (splited[i])
		i ++;
	j = i;
	while (0 < j)
	{
		number = (int *)malloc(sizeof(int));
		if (!number)
			return (-1);
		*number = ft_atoi(splited[j - 1]);
		if (!(*number))
			return (0);
		new = ft_lstnew(number);
		if (*lst == NULL)
			*lst = new;
		else
			ft_lstadd_front(lst, new);
		j --;
	}
	j = 0;
	while (splited[j])
		free(splited[j ++]);
	free(splited);
	return (i + 1);
}

void	make_order_3(t_list **stack_a)
{
	t_list	*highest;
	t_list	*curr;

	curr = *stack_a;
	highest = *stack_a;
	while (curr)
	{
		if (*(int *)curr->content > *(int *)highest->content)
		highest = curr;
		curr = curr->next;
	}
	if (*stack_a == highest)
		ra(stack_a);
	else if ((*stack_a)->next == highest)
		rra(stack_a);
	if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
		sa(stack_a);
}

int loadStackFromArgs(int argc, char **argv, t_list **stack_a)
{
	int i;

	if (argc <= 1)
		return 0;
	*stack_a = NULL;
	if (argc == 2 && !argv[1][0])
		return 1;
	else if (argc == 2)
	{
		return load_stack_one(argv[1], stack_a);
	}
	else
	{
		i = argc;
		while (0 < i)
		{
			if (!load_stack(argv[i], stack_a))
			{
				ft_printf("Error\n");
				return 1;
			}
			i++;
		}
		return (argc - 1);
	}
}

int	check_multiple(t_list *stack)
{
	t_list	*all;
	t_list	*check;

	check = stack;
	while (check)
	{
		all = check->next;
		while (all)
		{
			if (*(int *)all->content == *(int *)check->content)
				return (0);
			all = all->next;
		}
		check = check->next;
	}
	return (1);
}

/*
int main(int argc, char **argv)
{
	int 	i;
	int		j;
	int 	loadResult;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*curr;
	t_list	*next;


	loadResult = loadStackFromArgs(argc, argv, &stack_a);
	stack_b = NULL;
	if (loadResult == 0)
		return 0;
	else if (loadResult && !check_multiple(stack_a))
	{
		ft_printf("Error\n");
		return 1;
	}
	j = 0;
	while (j < loadResult - 4)
	{
		pb(&stack_b, &stack_a);
		j++;
	}
	make_order_3(&stack_a);
			curr = stack_a;
	while (curr)
	{
		ft_printf("b4 order3: %d\n", *(int *)curr->content);
		next = curr->next;
		curr = next;
	}
	select_sort(&stack_a, &stack_b);
		curr = stack_a;
	while (curr)
	{
		ft_printf("stack a: %d\n", *(int *)curr->content);
		next = curr->next;
		curr = next;
	}
	ft_lstclear(&stack_a, free);
	return 0;
}*/